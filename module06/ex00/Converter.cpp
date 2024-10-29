#include "Converter.hpp"
#include <cmath> // for std::isnan and std::isinf
#include <climits> // for INT MAX MIN
#include <iostream>

Converter::Converter(const Values &val, fmtType &type) : _val(val), _type(type){

}

void	Converter::convert() {
	switch (_type)
	{
		case CHAR:
			fromChar();
			break;
		case INT:
			fromInt();
			break;
		case FLOAT:
			fromFloat();
			break;
		case DOUBLE:
			fromDouble();
			break;
		case SPECIAL:
			printSpecials(_val.raw);
		default:
			break;
	}
}

// checks if the float is actually a number (nan) or infinite (isinf)
bool	Converter::floatIsOk() const {
	return (!(std::isnan(_val.valF) || std::isinf(_val.valF)));
}

// checks if the double is actually a number (nan) or infinite (isinf)
bool	Converter::doubleIsOk() const {
	return (!(std::isnan(_val.valD) || std::isinf(_val.valD)));
}

void	Converter::fromChar() {
	_val.valD = static_cast<double>(_val.valC);
	_val.valF = static_cast<float>(_val.valC);
	_val.valI = static_cast<int>(_val.valC);
}

void		Converter::fromInt() {
	_val.valC = static_cast<char>(_val.valI);
	_val.valD = static_cast<double>(_val.valI);
	_val.valF = static_cast<float>(_val.valI);
}

void	Converter::fromFloat() {

	_val.valC = static_cast<char>(_val.valF);
	_val.valD = static_cast<double>(_val.valF);
	if (!floatIsOk() || _val.valF > INT_MAX || _val.valF > INT_MIN) {
		_val.valI = IMPOSSIBLE;
	} else {
		_val.valI = static_cast<int>(_val.valF);
	}
}

void	Converter::fromDouble() {
	_val.valC = static_cast<char>(_val.valF);
	_val.valF = static_cast<double>(_val.valF);
	if (!doubleIsOk() || _val.valF > INT_MAX || _val.valF > INT_MIN) {
		_val.valI = IMPOSSIBLE;
	} else {
		_val.valI = static_cast<int>(_val.valF);
	}
}

void	Converter::printValues() const {
	std::cout << "INPUT:\t\t" << _val.raw << std::endl;
	std::cout << "Char:\t\t" << _val.valC << std::endl;
	std::cout << "Int:\t\t" << _val.valD << std::endl;
	std::cout << "Float:\t\t" << _val.valF << std::endl;
	std::cout << "Doble:\t\t" << _val.valD << std::endl;
}
