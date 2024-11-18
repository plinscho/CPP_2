#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat b1("Alice", 151);
        std::cout << b1 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 0);
        std::cout << b2 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 75);
        std::cout << b3 << std::endl;
        b3.incrementGrade();
        std::cout << b3 << std::endl;
        b3.decrementGrade();
        std::cout << b3 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
