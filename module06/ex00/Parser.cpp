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


// Returns a enum type and saves fmt in the parser.
fmtType	Parser::getType(const std::string &fmt) {
	if (onSpecial(fmt)) {
		return SPECIAL;
	} else if (onChar(fmt)){
		return CHAR;
	}

	fmtType retType;
	std::stringstream ss;
	int fmtLen = fmt.length();
	int i = 0;

	if (fmt[0] == '+' || fmt[0] == '-')
		ss << fmt[i++];

	retType = INT;
	for ( ; i < fmtLen; i++)
	{
		if (fmt[i] == '.' && retType != DOUBLE)
		{
			retType = DOUBLE;
			ss << fmt[i];
		}
		else if (fmt[i] == 'e' && i < fmtLen - 1
			&& (fmt[i + 1] == '-'
				|| fmt[i + 1] == '+'
				|| std::isdigit(fmt[i + 1])))
		{
			ss << fmt[i] << fmt[i + 1];
			i++;
			retType = DOUBLE;
		}
		else if (fmt[i] == 'f' && i == fmtLen - 1 && retType == DOUBLE)
			retType = FLOAT;
		else if (!std::isdigit(fmt[i]))
		{
			retType = NOT_VALID;
			i = fmtLen;
		}
		else
			ss << fmt[i];
	}
	if (retType == INT)
	{
		long lvalue;
		ss >> lvalue;
		if (ss.fail() || lvalue > INT_MAX || lvalue < INT_MIN) {
			retType = NOT_VALID;
		} else {
			ss >> _val.valI;
		}
	} else if (retType == FLOAT) {
		ss >> _val.valF;
	} else if (retType == DOUBLE) {
		ss >> _val.valD;
	}
	_val.raw = fmt;
	return (retType);
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
