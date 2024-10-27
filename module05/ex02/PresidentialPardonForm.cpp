#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("PresidentialPardonForm", 25, 5), _target(target) {

}

PresidentialPardonForm::~PresidentialPardonForm(){}

bool	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	try {
		if (!onIsSigned()) {
			throw FormIsNotSigned("Form is not signed!");
		}
		else if (executor.getGrade() <= this->getGradeExe()) {
			std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
			return true;
		} else {
			throw GradeTooLowException("Grade is too low to execute PresidentialPardon.");
		}
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return false;
	}
}