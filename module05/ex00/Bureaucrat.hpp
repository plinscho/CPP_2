#pragma once
#include <iostream>

class Bureaucrat {
	public:
	Bureaucrat(const std::string&, int&);
	~Bureaucrat();
	const std::string&	getName() const { return _name; }
	int					getGrade() const { return _grade; }

	private:
	const std::string	_name;
	int					_grade;
};
