#include "Parser.hpp"

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
	if (fmt.length() == 1) {
		_val.raw = fmt;
		_val.valC = fmt[0];
		return (true);
	}
	return (false);
}

// int numbers never have a '.' in it.
bool	Parser::onInt(const std::string &fmt) {
	if (fmt.find('.')) {
		return (false);
	}
	return (true);
}

//	If a '.' is found, search for the 'f' char.
bool	Parser::onFloat(const std::string &fmt) {
	if (fmt.find('f')) {
		return (true);
	}
	return (false);
}

// if a '.' if found but not a 'f', then it's a double
bool	Parser::onDouble(const std::string &fmt) {
	if (fmt.find('.')) {
		return (true);
	}
	return (false);
}

// Returns a enum type and saves fmt in the parser.
fmtType	Parser::getType(const std::string &fmt) {
	if (onSpecial(fmt)) {
		return SPECIAL;
	} else if (onChar(fmt)){
		return CHAR;
	} else if (onInt(fmt)) {
		return INT;
	} else if (onFloat(fmt)) {
		return FLOAT;
	} else if (onDouble(fmt)) {
		return DOUBLE;
	} else {
		return NOT_VALID;
	}
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