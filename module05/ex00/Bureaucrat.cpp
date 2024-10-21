#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("no-name"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
_name(name), _grade(grade) {
	if (name.empty()) {
		throw std::invalid_argument("Bureaucrat name is mandatory.");
	}
	try {
		if (grade <= 0)
			throw GradeTooHighException("Grade to high.");
		else if (grade > 150)
			throw GradeTooLowException("Grade too low.");
	}
	catch (const std::exception& e) {
		std::cout << "exception caught: " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	if (this != &copy) {
		*this = copy;
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	_name = rhs._name;
	_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

/*
Since grade 1 is the highest one and 150 the lowest,
incrementing a grade 3 should give a grade 2 to the bureaucrat.
*/
void Bureaucrat::incrementGrade() {
	try {
		--_grade;
		if (_grade < 0)
			throw GradeTooHighException("Grade too high.");
	} catch (const std::exception& e){
		std::cout << "exception caught: " << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	try {
		++_grade;
		if (_grade > 150) {
			throw GradeTooLowException("Grade too low.");
		}
	}
	catch (const std::exception &e) {
		std::cout << "exeption caught:" << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << "name: "<< bureaucrat.getName() << " bureaucrat grade: " << bureaucrat.getGrade() << std::endl;
	return out;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &error)
    : std::range_error(error) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &error)
    : std::range_error(error) {}

