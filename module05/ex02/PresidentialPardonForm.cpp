#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5){

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("PresidentialPardonForm", 25, 5), _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) 
: AForm(copy), _target(copy._target)
{

}


PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

bool	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	try {
		if (!onIsSigned()) {
			throw FormIsNotSigned("Form is not signed!");
		}
		else if (executor.getGrade() <= this->getGradeExe()) {
			std::cout << executor.getName() << " executed " << getName() << std::endl;
			std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
			return true;
		} else {
			throw GradeTooLowException("Grade is too low to execute PresidentialPardon.");
		}
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		std::cerr << executor.getName() << " could not execute " 
		<< getName() << std::endl;
		return false;
	}
}