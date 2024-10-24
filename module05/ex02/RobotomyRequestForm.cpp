#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :_target(target),
AForm("RobotomyRequestForm", 72, 45) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs){

}

RobotomyRequestForm::~RobotomyRequestForm(){}

bool	RobotomyRequestForm::execute(const Bureaucrat &executor) {
	srand(time(0)); // get a random number each time the program runs
	try {
		if (!onIsSigned()) {
			throw FormIsNotSigned("Form is not signed!");
		}
		else if (executor.getGrade() <= this->getGradeExe()) {
			std::cout << "BZbb ZZSHHHHHhhh..." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "More drilling noises..." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "Even more drilling noises..." << std::endl;
			int random = rand() % 100;
			if (random % 2 == 0) {
				std::cout << _target << " robotomozation was a SUCCES" << std::endl;
			} else {
				std::cout << _target << " robotomozation was a FAILURE" << std::endl;
			}
			return ;
		} else {
			throw GradeTooLowException("Grade is too low to execute Romotomy.");
		}
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
