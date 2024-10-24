#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Form f1("caca", 100, 110);
    Bureaucrat b1("Bob", 2);
	Bureaucrat b2("Peter", 100);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << f1 << std::endl;

	b2.decrementGrade();

	std::cout << "DECREMENTING GRADE\n" << b2 << std::endl;

	b2.signForm(f1);

	b2.incrementGrade();
	std::cout << "INCREMENTING GRADE\n" << b2 << std::endl;

	b2.signForm(f1);

    return (0);
}

