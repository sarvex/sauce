// This file was GENERATED by command:
//     pump.py new_injection.h.pump
// DO NOT EDIT BY HAND!!!

#ifndef SAUCE_INTERNAL_INJECTIONS_NEW_INJECTION_H_
#define SAUCE_INTERNAL_INJECTIONS_NEW_INJECTION_H_

#include <sauce/injector.h>
#include <sauce/memory.h>
#include <sauce/named.h>
#include <sauce/provider.h>
#include <sauce/internal/injection_binding.h>
#include <sauce/internal/injections/providing_injection.h>
#include <sauce/internal/key.h>
#include <sauce/internal/type_id.h>

namespace sauce {
namespace internal {
namespace injections {

/* *INDENT-OFF* */
template<typename Dependency, typename Scope, typename Constructor,
    typename Allocator>
class NewInjection;
/* *INDENT-ON* */

/* *INDENT-OFF* */
template<typename Dependency, typename Scope, typename Impl, typename Allocator>
class NewInjection<Dependency, Scope, Impl(), Allocator>:
  public ProvidingInjection<Dependency, Scope> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Scope, Impl(), Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;
  std::vector<std::string> dynamicDependencyNames;

public:

  typedef typename ProvidingInjection<Dependency,
      Scope>::InjectionPtr InjectionPtr;
  typedef typename ResolvedBinding<Dependency>::BindingPtr BindingPtr;

  NewInjection():
    allocator(),
    dynamicDependencyNames(0, unnamed()) {}

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
  Ptr provide(BindingPtr binding, InjectorPtr) const {
    Deleter deleter(sauce::static_pointer_cast<New>(
      static_cast<InjectionBinding<Dependency,
          Scope> *>(binding.get())->injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(), deleter);
    return provided;
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};
/* *INDENT-ON* */

/* *INDENT-OFF* */
template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1>
class NewInjection<Dependency, Scope, Impl(A1), Allocator>:
  public ProvidingInjection<Dependency, Scope> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Scope, Impl(A1), Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;
  std::vector<std::string> dynamicDependencyNames;

public:

  typedef typename ProvidingInjection<Dependency,
      Scope>::InjectionPtr InjectionPtr;
  typedef typename ResolvedBinding<Dependency>::BindingPtr BindingPtr;

  NewInjection():
    allocator(),
    dynamicDependencyNames(1, unnamed()) {}

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
  Ptr provide(BindingPtr binding, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<typename
        i::Key<A1>::Normalized>(injector, dynamicDependencyNames[0]));
    Deleter deleter(sauce::static_pointer_cast<New>(
      static_cast<InjectionBinding<Dependency,
          Scope> *>(binding.get())->injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids,
      std::string const name) const {
    this->template validateAcyclicHelper<A1>(injector, ids, name);
  }

  void setDynamicDependencyNames(std::vector<std::string> const &
      dynamicDependencyNames) {
    this->dynamicDependencyNames = dynamicDependencyNames;
    this->dynamicDependencyNames.resize(1, unnamed());
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};
/* *INDENT-ON* */

/* *INDENT-OFF* */
template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2>
class NewInjection<Dependency, Scope, Impl(A1, A2), Allocator>:
  public ProvidingInjection<Dependency, Scope> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Scope, Impl(A1, A2), Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;
  std::vector<std::string> dynamicDependencyNames;

public:

  typedef typename ProvidingInjection<Dependency,
      Scope>::InjectionPtr InjectionPtr;
  typedef typename ResolvedBinding<Dependency>::BindingPtr BindingPtr;

  NewInjection():
    allocator(),
    dynamicDependencyNames(2, unnamed()) {}

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
  Ptr provide(BindingPtr binding, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<typename
        i::Key<A1>::Normalized>(injector, dynamicDependencyNames[0]));
    typename Key<A2>::Ptr a2(this->template getHelper<typename
        i::Key<A2>::Normalized>(injector, dynamicDependencyNames[1]));
    Deleter deleter(sauce::static_pointer_cast<New>(
      static_cast<InjectionBinding<Dependency,
          Scope> *>(binding.get())->injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids,
      std::string const name) const {
    this->template validateAcyclicHelper<A1>(injector, ids, name);
    this->template validateAcyclicHelper<A2>(injector, ids, name);
  }

  void setDynamicDependencyNames(std::vector<std::string> const &
      dynamicDependencyNames) {
    this->dynamicDependencyNames = dynamicDependencyNames;
    this->dynamicDependencyNames.resize(2, unnamed());
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};
/* *INDENT-ON* */

/* *INDENT-OFF* */
template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3>
class NewInjection<Dependency, Scope, Impl(A1, A2, A3), Allocator>:
  public ProvidingInjection<Dependency, Scope> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Scope, Impl(A1, A2, A3), Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;
  std::vector<std::string> dynamicDependencyNames;

public:

  typedef typename ProvidingInjection<Dependency,
      Scope>::InjectionPtr InjectionPtr;
  typedef typename ResolvedBinding<Dependency>::BindingPtr BindingPtr;

  NewInjection():
    allocator(),
    dynamicDependencyNames(3, unnamed()) {}

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
  Ptr provide(BindingPtr binding, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<typename
        i::Key<A1>::Normalized>(injector, dynamicDependencyNames[0]));
    typename Key<A2>::Ptr a2(this->template getHelper<typename
        i::Key<A2>::Normalized>(injector, dynamicDependencyNames[1]));
    typename Key<A3>::Ptr a3(this->template getHelper<typename
        i::Key<A3>::Normalized>(injector, dynamicDependencyNames[2]));
    Deleter deleter(sauce::static_pointer_cast<New>(
      static_cast<InjectionBinding<Dependency,
          Scope> *>(binding.get())->injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids,
      std::string const name) const {
    this->template validateAcyclicHelper<A1>(injector, ids, name);
    this->template validateAcyclicHelper<A2>(injector, ids, name);
    this->template validateAcyclicHelper<A3>(injector, ids, name);
  }

  void setDynamicDependencyNames(std::vector<std::string> const &
      dynamicDependencyNames) {
    this->dynamicDependencyNames = dynamicDependencyNames;
    this->dynamicDependencyNames.resize(3, unnamed());
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};
/* *INDENT-ON* */

/* *INDENT-OFF* */
template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3, typename A4>
class NewInjection<Dependency, Scope, Impl(A1, A2, A3, A4), Allocator>:
  public ProvidingInjection<Dependency, Scope> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Scope, Impl(A1, A2, A3, A4), Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;
  std::vector<std::string> dynamicDependencyNames;

public:

  typedef typename ProvidingInjection<Dependency,
      Scope>::InjectionPtr InjectionPtr;
  typedef typename ResolvedBinding<Dependency>::BindingPtr BindingPtr;

  NewInjection():
    allocator(),
    dynamicDependencyNames(4, unnamed()) {}

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
  Ptr provide(BindingPtr binding, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<typename
        i::Key<A1>::Normalized>(injector, dynamicDependencyNames[0]));
    typename Key<A2>::Ptr a2(this->template getHelper<typename
        i::Key<A2>::Normalized>(injector, dynamicDependencyNames[1]));
    typename Key<A3>::Ptr a3(this->template getHelper<typename
        i::Key<A3>::Normalized>(injector, dynamicDependencyNames[2]));
    typename Key<A4>::Ptr a4(this->template getHelper<typename
        i::Key<A4>::Normalized>(injector, dynamicDependencyNames[3]));
    Deleter deleter(sauce::static_pointer_cast<New>(
      static_cast<InjectionBinding<Dependency,
          Scope> *>(binding.get())->injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3, a4), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids,
      std::string const name) const {
    this->template validateAcyclicHelper<A1>(injector, ids, name);
    this->template validateAcyclicHelper<A2>(injector, ids, name);
    this->template validateAcyclicHelper<A3>(injector, ids, name);
    this->template validateAcyclicHelper<A4>(injector, ids, name);
  }

  void setDynamicDependencyNames(std::vector<std::string> const &
      dynamicDependencyNames) {
    this->dynamicDependencyNames = dynamicDependencyNames;
    this->dynamicDependencyNames.resize(4, unnamed());
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};
/* *INDENT-ON* */

/* *INDENT-OFF* */
template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3, typename A4,
    typename A5>
class NewInjection<Dependency, Scope, Impl(A1, A2, A3, A4, A5), Allocator>:
  public ProvidingInjection<Dependency, Scope> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Scope, Impl(A1, A2, A3, A4, A5),
      Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;
  std::vector<std::string> dynamicDependencyNames;

public:

  typedef typename ProvidingInjection<Dependency,
      Scope>::InjectionPtr InjectionPtr;
  typedef typename ResolvedBinding<Dependency>::BindingPtr BindingPtr;

  NewInjection():
    allocator(),
    dynamicDependencyNames(5, unnamed()) {}

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
  Ptr provide(BindingPtr binding, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<typename
        i::Key<A1>::Normalized>(injector, dynamicDependencyNames[0]));
    typename Key<A2>::Ptr a2(this->template getHelper<typename
        i::Key<A2>::Normalized>(injector, dynamicDependencyNames[1]));
    typename Key<A3>::Ptr a3(this->template getHelper<typename
        i::Key<A3>::Normalized>(injector, dynamicDependencyNames[2]));
    typename Key<A4>::Ptr a4(this->template getHelper<typename
        i::Key<A4>::Normalized>(injector, dynamicDependencyNames[3]));
    typename Key<A5>::Ptr a5(this->template getHelper<typename
        i::Key<A5>::Normalized>(injector, dynamicDependencyNames[4]));
    Deleter deleter(sauce::static_pointer_cast<New>(
      static_cast<InjectionBinding<Dependency,
          Scope> *>(binding.get())->injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3, a4, a5), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids,
      std::string const name) const {
    this->template validateAcyclicHelper<A1>(injector, ids, name);
    this->template validateAcyclicHelper<A2>(injector, ids, name);
    this->template validateAcyclicHelper<A3>(injector, ids, name);
    this->template validateAcyclicHelper<A4>(injector, ids, name);
    this->template validateAcyclicHelper<A5>(injector, ids, name);
  }

  void setDynamicDependencyNames(std::vector<std::string> const &
      dynamicDependencyNames) {
    this->dynamicDependencyNames = dynamicDependencyNames;
    this->dynamicDependencyNames.resize(5, unnamed());
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};
/* *INDENT-ON* */

/* *INDENT-OFF* */
template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6>
class NewInjection<Dependency, Scope, Impl(A1, A2, A3, A4, A5, A6), Allocator>:
  public ProvidingInjection<Dependency, Scope> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Scope, Impl(A1, A2, A3, A4, A5, A6),
      Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;
  std::vector<std::string> dynamicDependencyNames;

public:

  typedef typename ProvidingInjection<Dependency,
      Scope>::InjectionPtr InjectionPtr;
  typedef typename ResolvedBinding<Dependency>::BindingPtr BindingPtr;

  NewInjection():
    allocator(),
    dynamicDependencyNames(6, unnamed()) {}

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
  Ptr provide(BindingPtr binding, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<typename
        i::Key<A1>::Normalized>(injector, dynamicDependencyNames[0]));
    typename Key<A2>::Ptr a2(this->template getHelper<typename
        i::Key<A2>::Normalized>(injector, dynamicDependencyNames[1]));
    typename Key<A3>::Ptr a3(this->template getHelper<typename
        i::Key<A3>::Normalized>(injector, dynamicDependencyNames[2]));
    typename Key<A4>::Ptr a4(this->template getHelper<typename
        i::Key<A4>::Normalized>(injector, dynamicDependencyNames[3]));
    typename Key<A5>::Ptr a5(this->template getHelper<typename
        i::Key<A5>::Normalized>(injector, dynamicDependencyNames[4]));
    typename Key<A6>::Ptr a6(this->template getHelper<typename
        i::Key<A6>::Normalized>(injector, dynamicDependencyNames[5]));
    Deleter deleter(sauce::static_pointer_cast<New>(
      static_cast<InjectionBinding<Dependency,
          Scope> *>(binding.get())->injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3, a4, a5, a6), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids,
      std::string const name) const {
    this->template validateAcyclicHelper<A1>(injector, ids, name);
    this->template validateAcyclicHelper<A2>(injector, ids, name);
    this->template validateAcyclicHelper<A3>(injector, ids, name);
    this->template validateAcyclicHelper<A4>(injector, ids, name);
    this->template validateAcyclicHelper<A5>(injector, ids, name);
    this->template validateAcyclicHelper<A6>(injector, ids, name);
  }

  void setDynamicDependencyNames(std::vector<std::string> const &
      dynamicDependencyNames) {
    this->dynamicDependencyNames = dynamicDependencyNames;
    this->dynamicDependencyNames.resize(6, unnamed());
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};
/* *INDENT-ON* */

/* *INDENT-OFF* */
template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7>
class NewInjection<Dependency, Scope, Impl(A1, A2, A3, A4, A5, A6, A7),
    Allocator>:
  public ProvidingInjection<Dependency, Scope> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Scope, Impl(A1, A2, A3, A4, A5, A6, A7),
      Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;
  std::vector<std::string> dynamicDependencyNames;

public:

  typedef typename ProvidingInjection<Dependency,
      Scope>::InjectionPtr InjectionPtr;
  typedef typename ResolvedBinding<Dependency>::BindingPtr BindingPtr;

  NewInjection():
    allocator(),
    dynamicDependencyNames(7, unnamed()) {}

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
  Ptr provide(BindingPtr binding, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<typename
        i::Key<A1>::Normalized>(injector, dynamicDependencyNames[0]));
    typename Key<A2>::Ptr a2(this->template getHelper<typename
        i::Key<A2>::Normalized>(injector, dynamicDependencyNames[1]));
    typename Key<A3>::Ptr a3(this->template getHelper<typename
        i::Key<A3>::Normalized>(injector, dynamicDependencyNames[2]));
    typename Key<A4>::Ptr a4(this->template getHelper<typename
        i::Key<A4>::Normalized>(injector, dynamicDependencyNames[3]));
    typename Key<A5>::Ptr a5(this->template getHelper<typename
        i::Key<A5>::Normalized>(injector, dynamicDependencyNames[4]));
    typename Key<A6>::Ptr a6(this->template getHelper<typename
        i::Key<A6>::Normalized>(injector, dynamicDependencyNames[5]));
    typename Key<A7>::Ptr a7(this->template getHelper<typename
        i::Key<A7>::Normalized>(injector, dynamicDependencyNames[6]));
    Deleter deleter(sauce::static_pointer_cast<New>(
      static_cast<InjectionBinding<Dependency,
          Scope> *>(binding.get())->injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3, a4, a5, a6, a7), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids,
      std::string const name) const {
    this->template validateAcyclicHelper<A1>(injector, ids, name);
    this->template validateAcyclicHelper<A2>(injector, ids, name);
    this->template validateAcyclicHelper<A3>(injector, ids, name);
    this->template validateAcyclicHelper<A4>(injector, ids, name);
    this->template validateAcyclicHelper<A5>(injector, ids, name);
    this->template validateAcyclicHelper<A6>(injector, ids, name);
    this->template validateAcyclicHelper<A7>(injector, ids, name);
  }

  void setDynamicDependencyNames(std::vector<std::string> const &
      dynamicDependencyNames) {
    this->dynamicDependencyNames = dynamicDependencyNames;
    this->dynamicDependencyNames.resize(7, unnamed());
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};
/* *INDENT-ON* */

/* *INDENT-OFF* */
template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8>
class NewInjection<Dependency, Scope, Impl(A1, A2, A3, A4, A5, A6, A7, A8),
    Allocator>:
  public ProvidingInjection<Dependency, Scope> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Scope, Impl(A1, A2, A3, A4, A5, A6, A7, A8),
      Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;
  std::vector<std::string> dynamicDependencyNames;

public:

  typedef typename ProvidingInjection<Dependency,
      Scope>::InjectionPtr InjectionPtr;
  typedef typename ResolvedBinding<Dependency>::BindingPtr BindingPtr;

  NewInjection():
    allocator(),
    dynamicDependencyNames(8, unnamed()) {}

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
  Ptr provide(BindingPtr binding, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<typename
        i::Key<A1>::Normalized>(injector, dynamicDependencyNames[0]));
    typename Key<A2>::Ptr a2(this->template getHelper<typename
        i::Key<A2>::Normalized>(injector, dynamicDependencyNames[1]));
    typename Key<A3>::Ptr a3(this->template getHelper<typename
        i::Key<A3>::Normalized>(injector, dynamicDependencyNames[2]));
    typename Key<A4>::Ptr a4(this->template getHelper<typename
        i::Key<A4>::Normalized>(injector, dynamicDependencyNames[3]));
    typename Key<A5>::Ptr a5(this->template getHelper<typename
        i::Key<A5>::Normalized>(injector, dynamicDependencyNames[4]));
    typename Key<A6>::Ptr a6(this->template getHelper<typename
        i::Key<A6>::Normalized>(injector, dynamicDependencyNames[5]));
    typename Key<A7>::Ptr a7(this->template getHelper<typename
        i::Key<A7>::Normalized>(injector, dynamicDependencyNames[6]));
    typename Key<A8>::Ptr a8(this->template getHelper<typename
        i::Key<A8>::Normalized>(injector, dynamicDependencyNames[7]));
    Deleter deleter(sauce::static_pointer_cast<New>(
      static_cast<InjectionBinding<Dependency,
          Scope> *>(binding.get())->injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3, a4, a5, a6, a7, a8), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids,
      std::string const name) const {
    this->template validateAcyclicHelper<A1>(injector, ids, name);
    this->template validateAcyclicHelper<A2>(injector, ids, name);
    this->template validateAcyclicHelper<A3>(injector, ids, name);
    this->template validateAcyclicHelper<A4>(injector, ids, name);
    this->template validateAcyclicHelper<A5>(injector, ids, name);
    this->template validateAcyclicHelper<A6>(injector, ids, name);
    this->template validateAcyclicHelper<A7>(injector, ids, name);
    this->template validateAcyclicHelper<A8>(injector, ids, name);
  }

  void setDynamicDependencyNames(std::vector<std::string> const &
      dynamicDependencyNames) {
    this->dynamicDependencyNames = dynamicDependencyNames;
    this->dynamicDependencyNames.resize(8, unnamed());
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};
/* *INDENT-ON* */

/* *INDENT-OFF* */
template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8, typename A9>
class NewInjection<Dependency, Scope, Impl(A1, A2, A3, A4, A5, A6, A7, A8, A9),
    Allocator>:
  public ProvidingInjection<Dependency, Scope> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Scope, Impl(A1, A2, A3, A4, A5, A6, A7, A8,
      A9), Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;
  std::vector<std::string> dynamicDependencyNames;

public:

  typedef typename ProvidingInjection<Dependency,
      Scope>::InjectionPtr InjectionPtr;
  typedef typename ResolvedBinding<Dependency>::BindingPtr BindingPtr;

  NewInjection():
    allocator(),
    dynamicDependencyNames(9, unnamed()) {}

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
  Ptr provide(BindingPtr binding, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<typename
        i::Key<A1>::Normalized>(injector, dynamicDependencyNames[0]));
    typename Key<A2>::Ptr a2(this->template getHelper<typename
        i::Key<A2>::Normalized>(injector, dynamicDependencyNames[1]));
    typename Key<A3>::Ptr a3(this->template getHelper<typename
        i::Key<A3>::Normalized>(injector, dynamicDependencyNames[2]));
    typename Key<A4>::Ptr a4(this->template getHelper<typename
        i::Key<A4>::Normalized>(injector, dynamicDependencyNames[3]));
    typename Key<A5>::Ptr a5(this->template getHelper<typename
        i::Key<A5>::Normalized>(injector, dynamicDependencyNames[4]));
    typename Key<A6>::Ptr a6(this->template getHelper<typename
        i::Key<A6>::Normalized>(injector, dynamicDependencyNames[5]));
    typename Key<A7>::Ptr a7(this->template getHelper<typename
        i::Key<A7>::Normalized>(injector, dynamicDependencyNames[6]));
    typename Key<A8>::Ptr a8(this->template getHelper<typename
        i::Key<A8>::Normalized>(injector, dynamicDependencyNames[7]));
    typename Key<A9>::Ptr a9(this->template getHelper<typename
        i::Key<A9>::Normalized>(injector, dynamicDependencyNames[8]));
    Deleter deleter(sauce::static_pointer_cast<New>(
      static_cast<InjectionBinding<Dependency,
          Scope> *>(binding.get())->injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3, a4, a5, a6, a7, a8, a9), deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids,
      std::string const name) const {
    this->template validateAcyclicHelper<A1>(injector, ids, name);
    this->template validateAcyclicHelper<A2>(injector, ids, name);
    this->template validateAcyclicHelper<A3>(injector, ids, name);
    this->template validateAcyclicHelper<A4>(injector, ids, name);
    this->template validateAcyclicHelper<A5>(injector, ids, name);
    this->template validateAcyclicHelper<A6>(injector, ids, name);
    this->template validateAcyclicHelper<A7>(injector, ids, name);
    this->template validateAcyclicHelper<A8>(injector, ids, name);
    this->template validateAcyclicHelper<A9>(injector, ids, name);
  }

  void setDynamicDependencyNames(std::vector<std::string> const &
      dynamicDependencyNames) {
    this->dynamicDependencyNames = dynamicDependencyNames;
    this->dynamicDependencyNames.resize(9, unnamed());
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};
/* *INDENT-ON* */

/* *INDENT-OFF* */
template<typename Dependency, typename Scope, typename Impl,
    typename Allocator, typename A1, typename A2, typename A3, typename A4,
    typename A5, typename A6, typename A7, typename A8, typename A9,
    typename A10>
class NewInjection<Dependency, Scope, Impl(A1, A2, A3, A4, A5, A6, A7, A8, A9,
    A10), Allocator>:
  public ProvidingInjection<Dependency, Scope> {

  typedef typename Key<Dependency>::Iface Iface;
  typedef typename Key<Dependency>::Ptr Ptr;
  typedef typename Allocator::template rebind<Impl>::other ImplAllocator;
  typedef NewInjection<Dependency, Scope, Impl(A1, A2, A3, A4, A5, A6, A7, A8,
      A9, A10), Allocator> New;
  typedef DisposalDeleter<Iface, New> Deleter;

  friend class DisposalDeleter<Iface, New>;

  mutable ImplAllocator allocator;
  std::vector<std::string> dynamicDependencyNames;

public:

  typedef typename ProvidingInjection<Dependency,
      Scope>::InjectionPtr InjectionPtr;
  typedef typename ResolvedBinding<Dependency>::BindingPtr BindingPtr;

  NewInjection():
    allocator(),
    dynamicDependencyNames(10, unnamed()) {}

  /**
   * Provide an Iface.
   *
   * A naked instance pointer is allocated and wrapped in a shared_ptr.  It is
   * also given a custom deleter, to dispose of the naked pointer with
   * dispose(Iface *).
   */
  Ptr provide(BindingPtr binding, InjectorPtr injector) const {
    typename Key<A1>::Ptr a1(this->template getHelper<typename
        i::Key<A1>::Normalized>(injector, dynamicDependencyNames[0]));
    typename Key<A2>::Ptr a2(this->template getHelper<typename
        i::Key<A2>::Normalized>(injector, dynamicDependencyNames[1]));
    typename Key<A3>::Ptr a3(this->template getHelper<typename
        i::Key<A3>::Normalized>(injector, dynamicDependencyNames[2]));
    typename Key<A4>::Ptr a4(this->template getHelper<typename
        i::Key<A4>::Normalized>(injector, dynamicDependencyNames[3]));
    typename Key<A5>::Ptr a5(this->template getHelper<typename
        i::Key<A5>::Normalized>(injector, dynamicDependencyNames[4]));
    typename Key<A6>::Ptr a6(this->template getHelper<typename
        i::Key<A6>::Normalized>(injector, dynamicDependencyNames[5]));
    typename Key<A7>::Ptr a7(this->template getHelper<typename
        i::Key<A7>::Normalized>(injector, dynamicDependencyNames[6]));
    typename Key<A8>::Ptr a8(this->template getHelper<typename
        i::Key<A8>::Normalized>(injector, dynamicDependencyNames[7]));
    typename Key<A9>::Ptr a9(this->template getHelper<typename
        i::Key<A9>::Normalized>(injector, dynamicDependencyNames[8]));
    typename Key<A10>::Ptr a10(this->template getHelper<typename
        i::Key<A10>::Normalized>(injector, dynamicDependencyNames[9]));
    Deleter deleter(sauce::static_pointer_cast<New>(
      static_cast<InjectionBinding<Dependency,
          Scope> *>(binding.get())->injection));
    Impl * impl = allocator.allocate(1);
    Ptr provided(new(impl) Impl(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10),
        deleter);
    return provided;
  }

  void validateAcyclic(InjectorPtr injector, TypeIds & ids,
      std::string const name) const {
    this->template validateAcyclicHelper<A1>(injector, ids, name);
    this->template validateAcyclicHelper<A2>(injector, ids, name);
    this->template validateAcyclicHelper<A3>(injector, ids, name);
    this->template validateAcyclicHelper<A4>(injector, ids, name);
    this->template validateAcyclicHelper<A5>(injector, ids, name);
    this->template validateAcyclicHelper<A6>(injector, ids, name);
    this->template validateAcyclicHelper<A7>(injector, ids, name);
    this->template validateAcyclicHelper<A8>(injector, ids, name);
    this->template validateAcyclicHelper<A9>(injector, ids, name);
    this->template validateAcyclicHelper<A10>(injector, ids, name);
  }

  void setDynamicDependencyNames(std::vector<std::string> const &
      dynamicDependencyNames) {
    this->dynamicDependencyNames = dynamicDependencyNames;
    this->dynamicDependencyNames.resize(10, unnamed());
  }

  void dispose(Iface * iface) const {
    Impl * impl = static_cast<Impl *>(iface);
    impl->~Impl(); // Must not throw
    allocator.deallocate(impl, 1);
  }
};
/* *INDENT-ON* */

}
}

namespace i = ::sauce::internal;
namespace inj = ::sauce::internal::injections;

}

#endif // SAUCE_INTERNAL_INJECTIONS_NEW_INJECTION_H_
