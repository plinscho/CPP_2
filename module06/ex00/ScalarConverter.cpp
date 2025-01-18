#include "ScalarConverter.hpp"
#include "Parser.hpp"
#include "Converter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter(){

}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs){
	(void)rhs;
	return *this;
}

void ScalarConverter::convert(const std::string &fmt) {

	fmtType		type;
	Parser 		parser;
	Values		values;
	
	parser.initVal();
	type = parser.getType(fmt);

	Converter	converter(parser.getValues(), type);
	converter.convert();
}
