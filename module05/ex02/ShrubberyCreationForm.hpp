#pragma once
#include <iostream>
#include "AForm.hpp"

/*
Required grades: sign 145, exec 137.
Create a file <target>_shrubbery in the working directory, 
and writes ASCII trees inside it.
*/

class ShrubberyCreationForm : public AForm {
	private:
	const std::string	_target;
	const std::string 	_fileName;

	public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	~ShrubberyCreationForm();

	bool	execute(const Bureaucrat &executor) const ;
};
