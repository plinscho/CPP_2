#pragma once
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm {
    public:
    AForm();
    AForm(const std::string&, int, int);
    AForm(const AForm &copy);
    AForm &operator=(const AForm &rhs);
    virtual ~AForm();

	bool				onIsSigned() const ;
	void				beSigned(Bureaucrat &);

    const std::string   getName() const ;
    int                 getGradeSign() const ;
    int                 getGradeExe() const ;

	virtual bool		execute(const Bureaucrat &executor) const = 0;

    class GradeTooHighException : public std::range_error {
        public:
        GradeTooHighException(const std::string&);
    };
    class GradeTooLowException : public std::range_error {
        public:
        GradeTooLowException(const std::string&);
    };
	class FormIsNotSigned : public std::range_error {
		public:
		FormIsNotSigned(const std::string &);
	};

    private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeSign;
    const int           _gradeExe;
};

std::ostream& operator<<(std::ostream& out, const AForm& bureaucrat);

