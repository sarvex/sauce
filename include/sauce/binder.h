#ifndef SAUCE_SAUCE_BINDER_H_
#define SAUCE_SAUCE_BINDER_H_

#include <memory>
#include <utility>

#include <sauce/internal/binding.h>
#include <sauce/internal/clause.h>
#include <sauce/internal/bindings/all.h>

namespace sauce {

template<typename Iface, typename Name, typename Ctor>
class ToClause;

/**
 * Binds to a specific constructor and allocator.
 */
template<typename Iface, typename Name, typename Ctor, typename Allocator>
class AllocateFromClause:
  public i::Clause<AllocateFromClause<Iface, Name, Ctor, Allocator> > {

  friend class ToClause<Iface, Name, Ctor>;
  friend class i::Clause<AllocateFromClause<Iface, Name, Ctor, Allocator> >;

  AllocateFromClause(i::BindingMap & bindingMap):
    i::Clause<AllocateFromClause<Iface, Name, Ctor, Allocator> >(bindingMap) {}

  static void activate(i::BindingMap & bindingMap) {
    i::BindingPointer binding(new b::New<Iface, Name, Ctor, Allocator>());
    bindingMap.insert(std::make_pair(binding->getKey(), binding));
  }
};

template<typename Iface>
class BindClause;

template<typename Iface, typename Name>
class NamedClause;

/**
 * Binds to a specific constructor allocating from the heap.
 */
template<typename Iface, typename Name, typename Ctor>
class ToClause:
  public i::Clause<ToClause<Iface, Name, Ctor> > {

  friend class BindClause<Iface>;
  friend class NamedClause<Iface, Name>;
  friend class i::Clause<ToClause<Iface, Name, Ctor> >;

  ToClause(i::BindingMap & bindingMap):
    i::Clause<ToClause<Iface, Name, Ctor> >(bindingMap) {}

  static void activate(i::BindingMap & bindingMap) {
    AllocateFromClause<Iface, Name, Ctor, std::allocator<Iface> >::activate(bindingMap);
  }

public:

  template<typename Allocator>
  AllocateFromClause<Iface, Name, Ctor, Allocator> allocateFrom() {
    return AllocateFromClause<Iface, Name, Ctor, Allocator>(this->pass());
  }

};

/**
 * Names the binding.
 */
template<typename Iface, typename Name>
class NamedClause:
  public i::Clause<NamedClause<Iface, Name> > {

  friend class BindClause<Iface>;
  friend class i::Clause<NamedClause<Iface, Name> >;

  NamedClause(i::BindingMap & bindingMap):
    i::Clause<NamedClause<Iface, Name> >(bindingMap) {}

  static void activate(i::BindingMap & bindingMap) {
    bindingMap.throwLater<PartialBindingFor<Iface, Name> >();
  }

public:

  template<typename Ctor>
  ToClause<Iface, Name, Ctor> to() {
    return ToClause<Iface, Name, Ctor>(this->pass());
  }

};

class Binder;

/**
 * A builder that creates a single binding.
 */
template<typename Iface>
class BindClause:
  public i::Clause<BindClause<Iface> > {

  friend class Binder;
  friend class i::Clause<BindClause<Iface> >;

  BindClause(i::BindingMap & bindingMap):
    i::Clause<BindClause<Iface> >(bindingMap) {}

  static void activate(i::BindingMap & bindingMap) {
    bindingMap.throwLater<PartialBindingFor<Iface, Unnamed> >();
  }

public:

  template<typename Name>
  NamedClause<Iface, Name> named() {
    return NamedClause<Iface, Name>(this->pass());
  }

  template<typename Ctor>
  ToClause<Iface, Unnamed, Ctor> to() {
    return ToClause<Iface, Unnamed, Ctor>(this->pass());
  }

};

class Bindings;

/**
 * Passed to modules to create bindings.
 */
class Binder {
  i::BindingMap & bindingMap;

  friend class Bindings;

  Binder(i::BindingMap & bindingMap):
    bindingMap(bindingMap) {}

public:

  /**
   * Begin binding the chosen interface.
   */
  template<typename Iface>
  BindClause<Iface> bind() {
    bindingMap.throwPending();
    return BindClause<Iface>(bindingMap);
  }

};

}

#endif // ifndef SAUCE_SAUCE_BINDER_H_