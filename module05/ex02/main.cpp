#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

# define BLUE "\e[0;34m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[1;33m"
# define RESET "\e[0m"


int main(void) {

	std::cout << RED << "*------------------Testing the ShrubberyCreationForm------------------*" << RESET << std::endl;
	Bureaucrat bureaucrat1("haha", 1);
	Bureaucrat bureaucrat2("braiiz", 10);
	ShrubberyCreationForm scf("Home");
	std::cout << "name: " << scf.getName() << std::endl;
	std::cout << "GradeToExec: " << scf.getGradeExe() << std::endl;
	std::cout << "GradeToSign: " << scf.getGradeSign() << std::endl;
	std::cout << std::endl;

	scf.execute(bureaucrat1);
	scf.beSigned(bureaucrat2);
	scf.execute(bureaucrat2);
	std::cout << std::endl;

	std::cout << RED << "*------------------Testing the RobotomyRequestForm------------------*" << RESET << std::endl;
	RobotomyRequestForm rrf("homeAgain");
	std::cout << "name: " << rrf.getName() << std::endl;
	std::cout << "GradeToExec: " << rrf.getGradeExe() << std::endl;
	std::cout << "GradeToSign: " << rrf.getGradeSign() << std::endl;
	std::cout << std::endl;

	rrf.execute(bureaucrat1);
	rrf.beSigned(bureaucrat2);
	rrf.execute(bureaucrat2);
	std::cout << std::endl;

	std::cout << RED << "*------------------Testing the PresidentialPardonForm------------------*" << RESET << std::endl;
	try {
		Bureaucrat bureaucrat3("haha", -40);
		PresidentialPardonForm ppf("homeAgain");
		std::cout << "name: " << ppf.getName() << std::endl;
		std::cout << "GradeToExec: " << ppf.getGradeExe() << std::endl;
		std::cout << "GradeToSign: " << ppf.getGradeSign() << std::endl;
		std::cout << std::endl;

		bureaucrat3.decrementGrade();
		std::cout << bureaucrat3 << std::endl;
		ppf.execute(bureaucrat3);
		ppf.beSigned(bureaucrat3);
		ppf.execute(bureaucrat3);
		std::cout << bureaucrat3 << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
		return 1;
	}
}