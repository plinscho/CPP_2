#include "Converter.hpp"
#include <cmath> // for std::isnan and std::isinf
#include <climits> // for INT MAX MIN
#include <limits>
#include <iomanip>
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
			break;
		case NOT_VALID:
			printNotValid();
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
	std::cout << "FROM CHAR" << std::endl;
	if (_val.valC < 33 || _val.valC > 126){
		std::cout << "Char: Non displayable" << std::endl;
	} else {
		std::cout << "Char: " << _val.valC << std::endl;
	}
	_val.valD = static_cast<double>(_val.valC);
	_val.valF = static_cast<float>(_val.valC);
	_val.valI = static_cast<int>(_val.valC);
	
	std::cout << "Int: " << _val.valI << std::endl;
	std::cout << "Double: " << _val.valD << ".0" << std::endl;
	std::cout << "Float: " << _val.valF << ".0f" << std::endl;
}

void		Converter::fromInt() {
	std::cout << "FROM INT" << std::endl;
	if (_val.valI > INT_MAX || _val.valI < INT_MIN ){
		std::cout << "Conversion Impossible, INT limit surpassed" << std::endl;
	} else {
		std::cout << "Char: '" << (char)(_val.valI) << "'" << std::endl;
		std::cout << "Int : " << _val.valI << std::endl;
		std::cout << "Double: " << std::fixed << std::setprecision(2)
				  << static_cast<double>(_val.valI) << std::endl;
		std::cout << "Float: " << static_cast<float>(_val.valI) <<  std::fixed 
					<< std::setprecision(2) << "f" << std::endl;
	}
}

void	Converter::fromFloat() {
	std::cout << "FROM FLOAT" << std::endl;
	std::cout << std::fixed;
	// char
	if (_val.valF < 127 && _val.valF > 0) {
		_val.valC = static_cast<char>(_val.valF);
		if (std::isprint(_val.valC)) {
			std::cout << "Char: '" << _val.valC << "'" << std::endl;
		} else {
			std::cout << "Char : Non printable" << std::endl;
		}
	} else {
		std::cout << "Char: Out of range" << std::endl;
	}

	// int
	_val.valI = static_cast<int>(_val.valF);
	if (_val.valI > INT_MAX || _val.valI > INT_MIN) {
		std::cout << "Int: Overflow (out of range)" << std::endl;
	} else {
		std::cout << "Int: " << _val.valI << std::endl;
	}

	// float
   	if (_val.valF > std::numeric_limits<float>::max() ||
		_val.valF < -std::numeric_limits<float>::max()) {
			std::cout << "Float: Overflow" << std::endl;
	} else {
		std::cout << "Float: " << _val.valF << "f" << std::endl;
	}

	// double
	if (_val.valF > std::numeric_limits<double>::max() ||
		_val.valF < -std::numeric_limits<double>::max()) {
			std::cout << "Double: Overflow" << std::endl;
	} else {
		_val.valD = static_cast<double>(_val.valF);
		std::cout << "Double: " << _val.valD << std::endl;
	}

}

void	Converter::fromDouble() {
	std::cout << "FROM DOUBLE" << std::endl;
	std::cout << std::fixed;
	// char
	if (_val.valD < 127 && _val.valD > 0) {
		_val.valC = static_cast<char>(_val.valD);
		if (std::isprint(_val.valC)) {
			std::cout << "Char: '" << _val.valC << "'" << std::endl;
		} else {
			std::cout << "Char : Non printable" << std::endl;
		}
	} else {
		std::cout << "Char: Out of range" << std::endl;
	}

	// Int
	_val.valI = static_cast<int>(_val.valD);
	if (_val.valI > INT_MAX || _val.valI > INT_MIN) {
		std::cout << "Int: Overflow (out of range)" << std::endl;
	} else {
		std::cout << "Int: " << _val.valI << std::endl;
	}

	// Float
	_val.valF = static_cast<float>(_val.valD);
	std::cout << "Float: " << _val.valF << "f" << std::endl;

	// Double
	std::cout << "Double :" << _val.valD << std::endl;
}

// remake function
void	Converter::printNotValid() const {
	std::cout << "INPUT:\t\t" << _val.raw << std::endl;
	std::cout << "Char:\t\t" << _val.valC << std::endl;
	std::cout << "Int:\t\t" << _val.valI << std::endl;
	std::cout << "Float:\t\t" << _val.valF << "f" << std::endl;
	std::cout << "Doble:\t\t" << _val.valD << std::endl;
}

void	Converter::printSpecials(const std::string &str) {
	std::cout << "Char: \t\timpossible" << std::endl;
	std::cout << "int: \t\timpossible" << std::endl;
	size_t pos = str.find("ff");
	if (pos != std::string::npos && pos == str.length() - 2) {
		std::cout << "float: \t\t" << str << std::endl;
	} else {
		std::cout << "float: \t\t" << str + "f" << std::endl;
	}
	std::cout << "double: \t" << str << std::endl;
}
