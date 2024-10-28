#include "Parser.hpp"
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
	if (fmt.fmtLen() == 1 && std::isprint(fmt[0]) && !std::isdigit(fmt[0])) {
		_val.raw = fmt;
		_val.valC = fmt[0];
		return (true);
	}
	return (false);
}

// int numbers never have a '.' in it.
bool	Parser::onInt(const std::string &fmt) {
	int i = 0;
	double D = 0;
	if (fmt[i] == '+' || fmt[i] == '-') {
		i++;
	}
	while (i < fmt.fmtLen()) {
		if (!std::isdigit(fmt[i])) {
			return (false);
		}
		i++;
	}
	D = std::atol(fmt.c_str());
	if (D < INT_MIN || D > INT_MAX) {
		return (false);
	} else {
		return (true);
	}
}

//	If a '.' is found, search for the 'f' char.
bool	Parser::onFloat(const std::string &fmt) {
	int i = 0;
	double D = 0;
	char c = ' ';
	bool dot = false;
	bool fletter = false;

	if (fmt[i] == '+' || fmt[i] == '-') {
		i++;
	}
	while (i < fmt.fmtLen()) {
		c = fmt[i];
		if (!std::isdigit(c)) {
			if (c == 'f') {
				fletter = true;
			} else if (c == '.'){
				dot = true;
			}
		}
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
	}

	fmtType retType;
	std::stringstream ss;
	size_t fmtLen = fmt.length();
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
		if (ss.fail() || lvalue > INT_MAX || lvalue < INT_MIN)
			retType = NOT_VALID;
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