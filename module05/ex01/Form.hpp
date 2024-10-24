#pragma once
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
    public:
    Form();
    Form(const std::string&, int, int);
    Form(const Form &copy);
    Form &operator=(const Form &rhs);
    ~Form();

	bool				onIsSigned() const ;
	void				beSigned(Bureaucrat &);

    const std::string   getName() const ;
    int                 getGradeSign() const ;
    int                 getGradeExe() const ;

    class GradeTooHighException : public std::range_error {
        public:
        GradeTooHighException(const std::string&);
    };
    class GradeTooLowException : public std::range_error {
        public:
        GradeTooLowException(const std::string&);
    };

    private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeSign;
    const int           _gradeExe;
};

std::ostream& operator<<(std::ostream& out, const Form& bureaucrat);

