#include "ScalarConverter.hpp"
#include "Parser.hpp"
#include <iostream>

void ScalarConverter::convert(const std::string &fmt) {
	fmtType	type;
	Parser parser;
	Values	values;
	
	parser.initVal();
	type = parser.getType(fmt);
	switch (type)
	{
		case SPECIAL:
			printSpecials(fmt);
			break;
		case CHAR:

			break;
		case INT:

			break;
		case FLOAT:

			break;
		case DOUBLE:

			break;
		case NOT_VALID:

			break;
		default:
			break;
	}
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