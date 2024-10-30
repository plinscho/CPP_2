#include "Parser.hpp"
#include <cstdlib>
#include <climits>
#include <sstream>

//	Check the subject special cases.
bool	Parser::onSpecial(const std::string &fmt) {
	if (fmt == "-inf" || fmt == "+inf" || fmt == "nan" 
		|| fmt == "-inff" || fmt == "+inff") {
			_val.raw = fmt;
		return (true);
	}
	return (false);
}

//	The len is always 1 for a char, 
//	and that is the first memory address of the string.
bool	Parser::onChar(const std::string &fmt) {
	if (fmt.length() == 1 && std::isprint(fmt[0]) && !std::isdigit(fmt[0])) {
		_val.raw = fmt;
		_val.valC = fmt[0];
		return (true);
	}
	return (false);
}

//	This function parses fmt trying to find a double, a float or a integer.
//	If no one is found, NOT_VALID is returned.
fmtType	Parser::numberParse(const std::string &fmt) {
		fmtType retType = NOT_VALID;
	std::stringstream ss(fmt);
	_val.raw = fmt;

	// Try to parse as int
	int intValue;
	ss >> intValue;
	if (!ss.fail() && ss.eof()) {
		_val.valI = intValue;
		return INT;
	}

	// Clear the stringstream state and reset it with the input string
	ss.clear();
	ss.str(fmt);

	// Try to parse as float
	float floatValue;
	ss >> floatValue;
	if (!ss.fail() && ss.eof()) {
		_val.valF = floatValue;
		return FLOAT;
	}

	// Clear the stringstream state and reset it with the input string
	ss.clear();
	ss.str(fmt);

	// Try to parse as double
	double doubleValue;
	ss >> doubleValue;
	if (!ss.fail() && ss.eof()) {
		_val.valD = doubleValue;
		return DOUBLE;
	}

	return retType;
}


// Returns a enum type and saves fmt in the parser.
fmtType	Parser::getType(const std::string &fmt) {
	if (onSpecial(fmt)) {
		return SPECIAL;
	} else if (onChar(fmt)){
		return CHAR;
	}
	return (numberParse(fmt));
}

// returns the parser saved values.
Values	Parser::getValues() const {
	return (_val);
}

void	Parser::initVal() {
	_val.raw = "";
	_val.valC = 0;
	_val.valI = 0;
	_val.valF = 0.0f;
	_val.valD = 0.0;
}
