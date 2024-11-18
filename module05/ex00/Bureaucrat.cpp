#include "Bureaucrat.hpp"
#include <iostream>

// Default constructor
Bureaucrat::Bureaucrat() : _name("no-name"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
_name(name) {
	if (name.empty()) {
		throw std::invalid_argument("Bureaucrat name is mandatory.");
	} else if (grade <= 0) {
		throw GradeTooHighException("Grade to high.");
	} else if (grade > 150) {
		throw GradeTooLowException("Grade too low.");
	} else {
		_grade = grade;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
: _name(copy._name), _grade(copy._grade) {

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs) {
		_grade = rhs._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

/*
Since grade 1 is the highest one and 150 the lowest,
incrementing a grade 3 should give a grade 2 to the bureaucrat.
*/
void Bureaucrat::incrementGrade() {
	if (_grade < 1)
		throw GradeTooHighException("Grade too high.");
	--_grade;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade > 150) {
		throw GradeTooLowException("Grade too low.");
	}
	++_grade;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << "Name: "<< bureaucrat.getName() << "\nBureaucrat grade: " << bureaucrat.getGrade() << std::endl;
	return out;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &error)
    : std::range_error(error) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &error)
    : std::range_error(error) {}

