#pragma once
#include "ScalarConverter.hpp"
#include <iostream>

class Converter {
	public:
		Converter(const Values &, fmtType &);
		
		char	toChar(const std::string &);
		int		toInt(const std::string &);
		float	toFloat(const std::string &);
		double	toDouble(const std::string &);
	private:
		bool	_err;
		fmtType	_type;
		Values	_val;
};