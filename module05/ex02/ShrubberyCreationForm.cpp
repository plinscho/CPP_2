#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
:_target(target), _fileName(target + "_shrubbery"), AForm(target, 145, 137){

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs){

}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

bool	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	try {
		if (!onIsSigned()) {
			throw FormIsNotSigned("Form is not signed!");
		}
		else if (executor.getGrade() <= this->getGradeExe()) {
			std::ofstream file(_fileName);
			if (file.is_open()){
				const std::string tree = "   oxoxooo x ooxoo\n"
										"  ooxoxo oo  oxoxooo\n"
										" oooo xxoxoo ooo ooox\n"
										" oxo o oxoxo  xoxxoxo\n"
										"  oxo xooxoooo o ooo\n"
										"    ooo\\oo\\  /o/o\n"
										"        \\  \\/ /\n"
										"         |   /\n"
										"     o'  |  |\n"
										"         | D|\n"
										"  o`     |  |\n"
										"         |  |\n"
										"  _______/____\\____";
			file << tree;
			file.close();
			} else {
				std::cerr << "Error. File could not be opened!" << std::endl;
				return ;
			}
		} else {
			throw GradeTooLowException("Grade is too low to execute Shrubbery.");
		}
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}