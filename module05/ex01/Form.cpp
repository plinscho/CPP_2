#include "Form.hpp"
#include <iostream>
#include <stdexcept>

Form::Form() : _name("UnkownForm"), _signed(false), _gradeExe(150), _gradeSign(150)
{
    
}



Form::Form(const std::string &name, int gradeSign, int gradeExe)
: _name(name), _gradeSign(gradeSign), _gradeExe(gradeExe)
{
    try
    {
        if (name.empty()) {
            throw std::invalid_argument("Name cannot be empty");
        } else if (gradeSign < 1 || gradeExe < 1) {
            throw GradeTooHighException("Grade too High.");
        } else if (gradeExe > 150 || gradeSign > 150) {
            throw GradeTooLowException("Grade too Low.");
        }
    }
    catch(GradeTooHighExeption &e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

Form::~Form(){}

Form::Form(const Form &copy) : 
    _name(copy._name),
    _gradeExe(copy._gradeExe), 
    _gradeSign(copy._gradeSign) 
{

}

Form &Form::operator=(const Form &rhs) {
    if (this != &rhs) {
        this->_signed = rhs._signed;
    }
    return *this;
}

Form::GradeTooHighExeption::GradeTooHighExeption(const std::string &msg) : std::range_error(msg) {

}

Form::GradeTooLowExeption::GradeTooLowExeption(const std::string &msg) : std::range_error(msg) {

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

