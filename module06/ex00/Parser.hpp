#pragma once
#include "ScalarConverter.hpp"
#include <iostream>

class Parser {
	public:

	fmtType	getType(const std::string &) ;
	bool	onSpecial(const std::string &);
	bool	onChar(const std::string &);
	bool	onInt(const std::string &);
	bool	onFloat(const std::string &);
	bool	onDouble(const std::string &);

	void	initVal();
	Values	getValues() const ;

	private:
	bool	_err = false;
	Values	_val;
};