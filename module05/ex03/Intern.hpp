#pragma once
#include <iostream>

class AForm;

class Intern {
	public:
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &rhs);
	~Intern();

	AForm*	makeForm(const std::string&, const std::string&) const ;
	private:

};