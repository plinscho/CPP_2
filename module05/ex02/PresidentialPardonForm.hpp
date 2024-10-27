#pragma once
#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
	private:
	const std::string	_target;

	public:
	PresidentialPardonForm(const std::string &target);
	~PresidentialPardonForm();

	bool	execute(const Bureaucrat &executor) const ;
};
