#include "ScalarConverter.hpp"
#include "Parser.hpp"
#include "Converter.hpp"
#include <iostream>

void ScalarConverter::convert(const std::string &fmt) {

	fmtType		type;
	Parser 		parser;
	Values		values;
	
	parser.initVal();
	type = parser.getType(fmt);

	Converter	converter(parser.getValues(), type);
	converter.convert();

}
