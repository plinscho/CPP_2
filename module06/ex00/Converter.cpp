#include "Converter.hpp"
#include <iostream>

Converter::Converter(const Values &val, fmtType &type) : _val(val), _type(type){

}

char	Converter::toChar(const std::string &fmt) {
	char c = fmt[0];
	return (c);
}

int		Converter::toInt(const std::string &fmt) {

}

float	Converter::toFloat(const std::string &fmt) {

}

double	Converter::toDouble(const std::string &fmt) {
	double D = 0;
	D = std::atol(fmt.c_str());

}