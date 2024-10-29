#pragma once
#include "ScalarConverter.hpp"
#include <iostream>

class Parser {
	public:

	fmtType	getType(const std::string &) ;
	bool	onSpecial(const std::string &);
	bool	onChar(const std::string &);

	void	initVal();
	Values	getValues() const ;

	private:
	Values	_val;
};