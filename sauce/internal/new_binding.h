#ifndef SAUCE_INTERNAL_NEW_BINDING_H_
#define SAUCE_INTERNAL_NEW_BINDING_H_

#include <sauce/injector.h>
#include <sauce/memory.h>
#include <sauce/named.h>
#include <sauce/provider.h>
#include <sauce/internal/apply_variadic.h>
#include <sauce/internal/binding.h>
#include <sauce/internal/key.h>
#include <sauce/internal/resolved_binding.h>
#include <sauce/internal/self_injector.h>
#include <sauce/internal/type_id.h>

namespace sauce {
namespace internal {

template<typename Dependency, typename Scope, typename Constructor, typename Allocator>
class NewBinding: public Binding<Dependency, Scope> {

  typedef NewBinding<Dependency, Scope, Constructor, Allocator> New;

  /**
   * A mixin for ApplyVariadic parameter concept types.
   */
  struct NewBindingFriend {
    template<typename T>
    void validateAcyclicHelper(New const & binding, InjectorPtr injector, TypeIds & ids, std::string dependencyName) {
      binding.template validateAcyclicHelper<T>(injector, ids, dependencyName);
    }

    template<typename T>
    typename Key<T>::Ptr getHelper(New const & binding, InjectorPtr injector, std::string dependencyName) {
      return binding.template getHelper<typename i::Key<T>::Normalized>(injector, dependencyName);
    }
  };

  friend class NewBindingFriend;

  struct InjectParameters {
    struct Passed {
      New const & binding;
      InjectorPtr & injector;

      Passed(New const & binding, InjectorPtr & injector):
        binding(binding), injector(injector) {}
    };

    template<typename T, int i, typename Passed>
    struct Parameter: public NewBindingFriend {
      typedef typename Key<T>::Ptr Ptr;

      Ptr yield(Passed passed) {
        New const & binding = passed.binding;
        InjectorPtr & injector = passed.injector;
        std::string dependencyName = binding.dynamicDependencyNames[i];

        return this->template getHelper<T>(binding, injector, dependencyName);
      }
    };
  };

  typedef ApplyConstructor<InjectParameters, Constructor, Allocator> Inject;
  typedef typename Inject::Constructed Impl;
  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr IfacePtr;
  typedef sauce::shared_ptr<Impl> ImplPtr;
  typedef DisposalDeleter<Iface, New> Deleter;

  std::vector<std::string> dynamicDependencyNames;

  struct ValidateAcyclicParameters {
    struct Passed {
      New const & binding;
      InjectorPtr & injector;
      TypeIds & ids;

      Passed(New const & binding, InjectorPtr & injector, TypeIds & ids):
        binding(binding), injector(injector), ids(ids) {}
    };

    template<typename T, int i, typename Passed>
    struct Parameter: public NewBindingFriend {
      void observe(Passed passed) {
        New const & binding = passed.binding;
        InjectorPtr & injector = passed.injector;
        TypeIds & ids = passed.ids;
        std::string dependencyName = binding.dynamicDependencyNames[i];

        this->template validateAcyclicHelper<T>(binding, injector, ids, dependencyName);
      }
    };
  };

  void validateAcyclic(InjectorPtr injector, TypeIds & ids) const {
    typename ValidateAcyclicParameters::Passed passed(*this, injector, ids);
    observeConstructor<ValidateAcyclicParameters, Constructor, Allocator>(passed);
  }

  void setDynamicDependencyNames(std::vector<std::string> const & dynamicDependencyNames) {
    this->dynamicDependencyNames = dynamicDependencyNames;
    this->dynamicDependencyNames.resize(Inject::arity(), unnamed());
  }

public:

  typedef typename ResolvedBinding<Dependency>::BindingPtr BindingPtr;

  NewBinding():
    dynamicDependencyNames(Inject::arity(), unnamed()) {}

  /**
   * Inject an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
  void inject(IfacePtr & injected, BindingPtr binding, InjectorPtr injector) const {
    typename InjectParameters::Passed passed(*this, injector);
    Deleter deleter(sauce::static_pointer_cast<New>(binding));
    ImplPtr impl(applyConstructor<InjectParameters, Constructor, Allocator>(passed), deleter);
    SelfInjector<Impl> selfInjector;
    selfInjector.setSelf(impl);
    injected = sauce::static_pointer_cast<Iface>(impl);
  }

  void dispose(Iface * iface) const {
    typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
    ImplAllocator allocator;
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }

};

}

namespace i = ::sauce::internal;

}

#endif // SAUCE_INTERNAL_NEW_BINDING_H_
