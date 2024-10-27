#pragma once
#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm {
	private:
	const std::string _target;

	public:
	RobotomyRequestForm(const std::string &target);
	~RobotomyRequestForm();

	bool	execute(const Bureaucrat &executor) const;
};
