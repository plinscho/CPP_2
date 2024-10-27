#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "AForm.hpp"

Intern::Intern(){

}

Intern::~Intern(){

}

Intern::Intern(const Intern &copy) {
	if (this != &copy) {
		*this = copy;
	}
}

Intern &Intern::operator=(const Intern &rhs){
	(void)rhs;
	return *this;
}

AForm*	Intern::makeForm(const std::string &name, const std::string &target) const {
	if (name.empty() || target.empty()){
		std::cerr << "Error. A name and a target is needed." << std::endl;
		return NULL;
	}
	AForm* forms[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), 
						new PresidentialPardonForm(target)};
	const std::string formNames[] = {"shrubbery form", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3 ; i++) {
		if (formNames[i] == name){
			std::cout << "Intern creates " << name << " form for " << target << std::endl;
			return forms[i];
		}
	}
	return NULL;
}


