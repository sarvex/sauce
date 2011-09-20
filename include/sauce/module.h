#ifndef SAUCE_SAUCE_MODULE_H_
#define SAUCE_SAUCE_MODULE_H_

#include <memory>

#include <sauce/internal/bindings.h>

namespace sauce {

/**
 * The default set of scopes that bindings may choose from.
 *
 * To define your own set of scopes, declare a Scopes enum in your module.
 *
 * Note that most applications should not need this degree of customization:
 * the granularities suggested by the singleton, session and request scopes
 * are usually applicable, even in contexts other than the web.
 */
enum DefaultScopes {
  SINGLETON_SCOPE,
  SESSION_SCOPE,
  REQUEST_SCOPE
};

template<typename Iface, typename Constructor, typename Allocator = std::allocator<void> >
class Bind {
public:

  template<typename Injector>
  static ::sauce::internal::bindings::New<Injector, Iface, Allocator,
                                          Constructor> * bindings(Iface) {
    return NULL;
  }

};

}

#endif // ifndef SAUCE_SAUCE_MODULE_H_