#include "Converter.hpp"
#include <cmath> // for std::isnan and std::isinf
#include <climits> // for INT MAX MIN
#include <limits>
#include <iomanip>
#include <iostream>

#define TAB

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

void Converter::printValues() const {
    std::cout << "Char:\t\t";
    if (_val.valI >= 0 && _val.valI <= 127 && std::isprint(_val.valC)) {
        std::cout << "'" << _val.valC << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }

    std::cout << "Int:\t\t" << _val.valI << std::endl;

    if (floatIsOk()) {
        std::cout << "Float:\t\t" << std::fixed << std::setprecision(1) << _val.valF << "f" << std::endl;
    } else {
        std::cout << "Float:\t\timpossible" << std::endl;
    }

    if (doubleIsOk()) {
        std::cout << "Double:\t\t" << std::fixed << std::setprecision(1) << _val.valD << std::endl;
    } else {
        std::cout << "Double:\t\timpossible" << std::endl;
    }
}

// Works OK
void	Converter::fromChar() {
	std::cout << "FROM CHAR" << std::endl;

	_val.valD = static_cast<double>(_val.valC);
	_val.valF = static_cast<float>(_val.valC);
	_val.valI = static_cast<int>(_val.valC);
	printValues();
}

void		Converter::fromInt() {
	std::cout << "FROM INT: " << _val.valI << std::endl;
	if (_val.valI > INT_MAX || _val.valI < INT_MIN ){
		std::cout << "Conversion Impossible, INT limit surpassed!" << std::endl;
		return ;
	} else {
        _val.valC = static_cast<char>(_val.valI);
        _val.valD = static_cast<double>(_val.valI);
        _val.valF = static_cast<float>(_val.valI);
		printValues();
	}
}

void	Converter::fromFloat() {
	std::cout << "FROM FLOAT" << std::endl;

	_val.valC = static_cast<char>(_val.valF);
	_val.valI = static_cast<int>(_val.valF);
	_val.valD = static_cast<double>(_val.valF);
	printValues();
}

void	Converter::fromDouble() {
	std::cout << "FROM DOUBLE" << std::endl;

	_val.valC = static_cast<char>(_val.valD);
	_val.valI = static_cast<int>(_val.valD);
	_val.valF = static_cast<float>(_val.valD);
	printValues();
}

// remake function
void	Converter::printNotValid() const {
	std::cout << "INPUT NOT VALID!:\t\t" << _val.raw << std::endl;
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
