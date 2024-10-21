#pragma once
#include <iostream>

class Bureaucrat {
	public:
	Bureaucrat();
	Bureaucrat(const std::string&, int);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();

	const std::string&	getName() const { return _name; }
	int					getGrade() const { return _grade; }
	void				incrementGrade();
	void				decrementGrade();

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
