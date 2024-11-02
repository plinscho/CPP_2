#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {

}

Base*	generate(void) {
    std::srand(time(0));
    int nr = rand();
    if (nr % 3 == 0) {
        return static_cast<Base *>(new A());
	} else if (nr % 2 == 0) {
        return static_cast<Base *>(new B());
	} else {
        return static_cast<Base *>(new C());
	}
}

void	identify(Base* p) {
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "ptr: " << p << " is class A" << std::endl;
    else if (dynamic_cast<B *>(p) != 0)
        std::cout << "ptr: " << p << " is class B" << std::endl;
    else
        std::cout << "ptr: " << p << " is class C" << std::endl;
}

void	identify(Base &p) {
    if (dynamic_cast<A *>(&p) != NULL)
        std::cout << "ptr by Ref: " << &p << " is class A" << std::endl;
    else if (dynamic_cast<B *>(&p) != 0)
        std::cout << "ptr by Ref: " << &p << " is class B" << std::endl;
    else
        std::cout << "ptr by Ref: " << &p << " is class C" << std::endl;
}
