#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    Base *classID = generate();

    identify(classID);
    identify(*classID);

    std::cout << "---------------TEST---------------" << std::endl;

    A a;
    identify(&a);
    B b;
    identify(&b);
    C c;
    identify(&c);

    delete classID;
    return 0;
}