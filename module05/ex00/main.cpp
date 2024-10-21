#include "Bureaucrat.hpp"
#include <iostream>


int main()
{
	Bureaucrat b1("mosan", 15);
	std::cout << b1 << std::endl;

	for(int i = 0; i < 14; ++i)
		b1.incrementGrade();

	std::cout << b1 << std::endl;

	b1.incrementGrade();

	std::cout << b1 << std::endl;

	for(int i = 0; i < 151; ++i)
		b1.decrementGrade();

	std::cout << b1 << std::endl;


	Bureaucrat b2("mamoussa", 0);
	return 0;
}