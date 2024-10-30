#pragma once
#include "ScalarConverter.hpp"
#include <iostream>

class Converter {
	public:
		Converter(const Values &, fmtType &);
		void	convert();
		void	fromChar();
		void	fromInt();
		void	fromFloat();
		void	fromDouble();

		bool	floatIsOk() const ;
		bool	doubleIsOk() const ;
		void	printNotValid() const ;
		void	printSpecials(const std::string&);
	private:
		Values	_val;
		fmtType	_type;
};