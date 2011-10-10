#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <sauce/sauce.h>

using ::testing::Sequence;
using ::testing::Return;

using ::sauce::Binder;
using ::sauce::Named;

namespace sauce {
namespace test {

struct C {};
struct N {};

TEST(BindingTest, shouldThrowExceptionWhenGettingAnUnboundIface) {
  Injector injector(Bindings().createInjector());
  ASSERT_THROW((injector.get<C>()), ::sauce::UnboundException);
}

struct B;

struct A {
  A(SAUCE_SHARED_PTR<B>) {}
};

struct B {
  B(SAUCE_SHARED_PTR<A>) {}
};

void CircularModule(Binder & binder) {
  binder.bind<A>().to<A(B)>();
  binder.bind<B>().to<B(A)>();
}

TEST(BindingTest, shouldThrowExceptionWhenResolvingCircularDependency) {
  Injector injector(Bindings().add(&CircularModule).createInjector());
  ASSERT_THROW((injector.get<A>()), ::sauce::CircularDependencyException);
}

void IncompleteModule(Binder & binder) {
  binder.bind<C>();
}

TEST(BindingTest, shouldThrowExceptionOnPartialBinding) {
  ASSERT_THROW(
    Bindings().add(&IncompleteModule).createInjector(),
    ::sauce::PartialBindingException);
}

void IncompleteNamedModule(Binder & binder) {
  binder.bind<A>().named<N>();
}

TEST(BindingTest, shouldThrowExceptionOnPartialNamedBinding) {
  ASSERT_THROW(
    Bindings().add(&IncompleteNamedModule).createInjector(),
    ::sauce::PartialBindingException);
}

struct Animal {
  virtual std::string says() = 0;
};

struct Cat: Animal {
  std::string says() { return "Meow"; }
};

struct Water {};
struct Fish: Animal {
  std::string says() { return "Blub blub"; }
};

struct Farm {};
struct Cow: Animal {
  std::string says() { return "Moo"; }
};

struct Pond {
  SAUCE_SHARED_PTR<Animal> animal;

  Pond(SAUCE_SHARED_PTR<Animal> animal):
    animal(animal) {}
};

void AnimalModule(Binder & binder) {
  binder.bind<Animal>().to<Cat()>();
  binder.bind<Animal>().named<Water>().to<Fish()>();
  binder.bind<Animal>().named<Farm>().to<Cow()>();

  binder.bind<Pond>().to<Pond(Named<Animal, Water>)>();
}

TEST(BindingTest, shouldProvidedNamedDependencies) {
  Injector injector(Bindings().add(&AnimalModule).createInjector());

  EXPECT_EQ("Meow",      (injector.get<Animal>()->says()));
  EXPECT_EQ("Blub blub", (injector.get<Animal, Water>()->says()));
  EXPECT_EQ("Moo",       (injector.get<Named<Animal, Farm> >()->says()));

  EXPECT_EQ("Blub blub", (injector.get<Pond>()->animal->says()));
}

}
}