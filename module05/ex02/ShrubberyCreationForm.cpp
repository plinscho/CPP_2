#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
: AForm(target, 145, 137), _target(target), _fileName(target + "_shrubbery") {

}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

bool	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	try {
		if (!onIsSigned()) {
			throw FormIsNotSigned("Form is not signed!");
		}
		else if (executor.getGrade() <= this->getGradeExe()) {
			std::ofstream file(_fileName.c_str());
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
			return true;
			} else {
				std::cerr << "Error. File could not be opened!" << std::endl;
				return false;
			}
		} else {
			throw GradeTooLowException("Grade is too low to execute Shrubbery.");
		}
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return false;
	}
}