#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
AForm("RobotomyRequestForm", 72, 45), _target(target) {

}

RobotomyRequestForm::~RobotomyRequestForm(){}

bool	RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	srand(time(0)); // get a random number each time the program runs
	try {
		if (!onIsSigned()) {
			throw FormIsNotSigned("Form is not signed!");
		}
		else if (executor.getGrade() <= this->getGradeExe()) {
			std::cout << "BZbb ZZSHHHHHhhh..." << std::endl;
			std::cout << "More drilling noises..." << std::endl;
			std::cout << "Even more drilling noises..." << std::endl;
			int random = rand() % 100;
			if (random % 2 == 0) {
				std::cout << _target << " robotomozation was a SUCCES" << std::endl;
			} else {
				std::cout << _target << " robotomozation was a FAILURE" << std::endl;
			}
			std::cout << executor.getName() << " executed " << getName() << std::endl;
			return true;
		} else {
			throw GradeTooLowException("Grade is too low to execute Romotomy.");
		}
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		std::cerr << executor.getName() << " could not execute " 
		<< getName() << std::endl;
		return false;
	}
}
