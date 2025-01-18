#pragma once
#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm {
	private:
	std::string _target;

	public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
	~RobotomyRequestForm();

	bool	execute(const Bureaucrat &executor) const;
};
