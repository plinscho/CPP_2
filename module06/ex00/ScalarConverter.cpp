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
	if (type == NOT_VALID) {
		values.valC = IMPOSSIBLE;
		values.valD = IMPOSSIBLE;
		values.valF = IMPOSSIBLE;
		values.valI = IMPOSSIBLE;
	} else {
		converter.convert();
	}
	converter.printValues();	
}

void	printSpecials(const std::string &str) {
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
