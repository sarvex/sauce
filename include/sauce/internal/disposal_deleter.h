#ifndef SAUCE_SAUCE_INTERNAL_DISPOSAL_DELETER_H_
#define SAUCE_SAUCE_INTERNAL_DISPOSAL_DELETER_H_

#include <sauce/memory.h>

namespace sauce {
namespace internal {

namespace bindings {
template<typename Dependency, typename Scope>
class NakedBinding;
}

namespace b = ::sauce::internal::bindings;

/**
 * A smart pointer deleter that diposes with a given binding.
 */
template<typename Dependency, typename Scope>
class DisposalDeleter {
  typedef typename Key<Dependency>::Iface Iface;
  typedef sauce::shared_ptr<b::NakedBinding<Dependency, Scope> > BindingPtr;

  friend class b::NakedBinding<Dependency, Scope>;

  BindingPtr binding;

  DisposalDeleter(BindingPtr binding):
    binding(binding) {}

public:

  /**
   * Cast and dispose the given Iface instance.
   */
  void operator()(Iface * iface) const {
    binding->dispose(iface);
  }
};

}

namespace i = ::sauce::internal;

}

#endif // SAUCE_SAUCE_INTERNAL_DISPOSAL_DELETER_H_
