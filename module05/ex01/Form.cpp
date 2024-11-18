#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

Form::Form() : _name("UnkownForm"), _signed(false), _gradeSign(150), _gradeExe(150)
{
	
}

Form::Form(const std::string &name, int gradeSign, int gradeExe)
: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExe(gradeExe)
{
	if (name.empty()) {
		throw std::invalid_argument("Name cannot be empty");
	} else if (gradeSign < 1 || gradeExe < 1) {
		throw GradeTooHighException("Grade too high.");
	} else if (gradeExe > 150 || gradeSign > 150) {
	  	throw GradeTooLowException("Grade too low.");
	}
}

Form::~Form(){}

Form::Form(const Form &copy) : 
	_name(copy._name),
	_signed(copy._signed),
	_gradeSign(copy._gradeSign),
	_gradeExe(copy._gradeExe) 
{

}

Form &Form::operator=(const Form &rhs) {
	if (this != &rhs) {
		this->_signed = rhs._signed;
	}
	return *this;
}

Form::GradeTooHighException::GradeTooHighException(const std::string &msg) : std::range_error(msg) {

}

Form::GradeTooLowException::GradeTooLowException(const std::string &msg) : std::range_error(msg) {

}

const std::string Form::getName() const {
	return _name;
}

int   Form::getGradeExe() const {
	return _gradeExe;
}

int   Form::getGradeSign() const {
	return _gradeSign;
}

bool	Form::onIsSigned() const {
	return (this->_signed);
}

void	Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeSign) {
		this->_signed = true;
	} else {
		throw GradeTooLowException("Grade too low to sign form.");
	}
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << "Form Info:\nForm name: "<< form.getName() << "\nForm sign grade: " << form.getGradeSign()
	<< "\nForm exec grade: " << form.getGradeExe() << std::endl;
	return out;
}

