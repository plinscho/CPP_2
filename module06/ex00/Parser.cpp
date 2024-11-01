#include "Parser.hpp"
#include <cstdlib>
#include <limits>
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

	std::stringstream ss;
	size_t	fmtLen = fmt.length();
	size_t i = 0;
	_val.raw = fmt;

	if (fmt[0] == '+' || fmt[0] == '-') {
		ss << fmt[i++];
	}
	fmtType retType = INT; // Start assuming we have an
	for ( ; i < fmtLen ; i++) {
		// check for '.' 
		if (fmt[i] == '.') {
			retType = DOUBLE;
		} 
		// check for 'f' 
		else if (fmt[i] == 'f' && i == fmtLen - 1 && retType == DOUBLE){
			retType = FLOAT;
		}
		else if (!std::isdigit(fmt[i])) { // if not '.', 'f', or digit, then its not valid.
			retType = NOT_VALID;
			i = fmtLen;
		} else {
			ss << fmt[i];
		}
	}

	switch (retType)
	{
	case FLOAT:
		ss >> _val.valF;
		break;
	
	case DOUBLE:
		ss >> _val.valD;
		break;
	case INT:
		long lValue = 0;
		ss >> lValue;
		if (ss.fail()
			|| lValue > std::numeric_limits<int>::max()
			|| lValue < std::numeric_limits<int>::min()) {
				retType = NOT_VALID;
			}
		break;
	case NOT_VALID:
		break;
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
