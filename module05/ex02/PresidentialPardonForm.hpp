#pragma once
#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
	private:
	const std::string	_target;

	public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
	~PresidentialPardonForm();

	bool	execute(const Bureaucrat &executor) const ;
};
