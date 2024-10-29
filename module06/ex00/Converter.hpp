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
		void	printValues() const ;
	private:
		Values	_val;
		fmtType	_type;
};