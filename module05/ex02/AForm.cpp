#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

AForm::AForm() : _name("UnkownAForm"), _signed(false), _gradeSign(150), _gradeExe(150)
{
    
}

AForm::AForm(const std::string &name, int gradeSign, int gradeExe)
: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExe(gradeExe)
{
    try
    {
        if (name.empty()) {
            throw std::invalid_argument("Name cannot be empty");
        } else if (gradeSign < 1 || gradeExe < 1) {
			throw GradeTooHighException("Grade too high.");
        } else if (gradeExe > 150 || gradeSign > 150) {
          	throw GradeTooLowException("Grade too low.");
        }
    }
    catch(GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

AForm::~AForm(){}

AForm::AForm(const AForm &copy) : 
    _name(copy._name),
	_signed(copy._signed),
    _gradeSign(copy._gradeSign),
    _gradeExe(copy._gradeExe) 
{

}

AForm &AForm::operator=(const AForm &rhs) {
    if (this != &rhs) {
        this->_signed = rhs._signed;
    }
    return *this;
}

AForm::GradeTooHighException::GradeTooHighException(const std::string &msg) : std::range_error(msg) {

}

AForm::GradeTooLowException::GradeTooLowException(const std::string &msg) : std::range_error(msg) {

}

AForm::FormIsNotSigned::FormIsNotSigned(const std::string &msg) : std::range_error(msg) {

}

const std::string AForm::getName() const {
    return _name;
}

int   AForm::getGradeExe() const {
    return _gradeExe;
}

int   AForm::getGradeSign() const {
    return _gradeSign;
}

bool	AForm::onIsSigned() const {
	return (this->_signed);
}

void	AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeSign) {
		this->_signed = true;
	} else {
		throw GradeTooLowException("Grade too low to sign Aform.");
	}
}

std::ostream &operator<<(std::ostream &out, const AForm &Aform) {
	out << "AForm Info:\nAForm name: "<< Aform.getName() << "\nAForm sign grade: " << Aform.getGradeSign()
	<< "\nAForm exec grade: " << Aform.getGradeExe() << std::endl;
	return out;
}

