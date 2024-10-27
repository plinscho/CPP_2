#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

# define BLUE "\e[0;34m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[1;33m"
# define RESET "\e[0m"



int main() {


	std::cout << GREEN << "*------------------- Creating a robotomy request form -------------------*" << RESET << std::endl;
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (!rrf) return (1);
	Bureaucrat b("Josep", 5);
	rrf->beSigned(b);
	rrf->execute(b);
	std::cout << std::endl;


	std::cout << GREEN << "*------------------- Creating a shrubbery creation form -------------------*" << RESET << std::endl;
	AForm* scf;
	scf = someRandomIntern.makeForm("shrubbery form", "Pedro");
	scf->beSigned(b);
	scf->execute(b);
	return 0;
}