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
	~ShrubberyCreationForm();

	bool	execute(const Bureaucrat &executor) const ;
};

/*
	std::cout << executor.getName() << " executed " << getName() << std::endl;

 {
		std::cout << _name << " executed " << form.getName() << std::endl;
	} else {
		std::cerr << _name << " could not execute " << form.getName() << std::endl;
	}

*/