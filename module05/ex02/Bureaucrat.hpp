#pragma once
#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat {
	public:
	Bureaucrat();
	Bureaucrat(const std::string&, int);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();

	void				signForm(AForm &);

	const std::string&	getName() const { return _name; }
	int					getGrade() const { return _grade; }
	void				incrementGrade();
	void				decrementGrade();

	void				executeForm(const AForm &) const ;

	private:
	std::string			_name;
	int					_grade;



	class GradeTooHighException : public std::range_error {
		public:
		GradeTooHighException(const std::string &msg);
	};
	class GradeTooLowException : public std::range_error {
		public:
		GradeTooLowException(const std::string &msg);
	};

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
