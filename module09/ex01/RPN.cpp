#include "RPN.hpp"

RPN::RPN() {
	_result = 0;
}

RPN::~RPN() {

}

RPN::RPN(const RPN &copy) {
	*this = copy;
}

RPN &RPN::operator=(const RPN &rhs) {
	if (this != &rhs) {
		_op = rhs._op;
	}
	return (*this);
}

bool	RPN::parseArg(const char* argv) {
	if (!argv || argv == NULL) return (false);
	
	std::stringstream str(argv);
	std::string token;
	while(std::getline(str, token, ' ')) {
		if (onDigit(token)) {
			loadNumberStack(token);
		} else if (_op.size() >= 2) {
			if (!performOperation(token)) return (false);
		} else {
			std::cerr << "Error. Only numbers and \"+ - * /\" operators accepted!" << std::endl;
			return (false);
		}
	}
	// Check if there is exactly one element left in the stack
	if (_op.size() != 1) {
		std::cerr << "Error. Invalid input." << std::endl;
		return false;
	}
	return (true);
}

bool	RPN::onDigit(const std::string token) {
	return (token.find_first_not_of("0123456789") == std::string::npos);
}

void	RPN::loadNumberStack(const std::string token) {
	_op.push(std::atof(token.c_str()));
}

bool	RPN::performOperation(const std::string &op) {
	float op2 = _op.top();
	_op.pop();
	float op1 = _op.top();
	_op.pop();
	float result;

	if (op == "+") {
		result = op1 + op2;
		std::cout << "Add:\t" << op1 << " + " << op2 << " = " << result << std::endl;
	} else if (op == "-") {
		result = op1 - op2;
		std::cout << "Sub:\t" << op1 << " - " << op2 << " = " << result << std::endl;
	} else if (op == "*") {
		result = op1 * op2;
		std::cout << "Mult:\t" << op1 << " * " << op2 << " = " << result << std::endl;
	} else if (op == "/") {
		if (op2 == 0) {
			std::cout << "Error. Division by zero." << std::endl;
			return (false);
		}
		result = op1 / op2;
		std::cout << "Div:\t" << op1 << " / " << op2 << " = " << result << std::endl;
	} else {
		std::cerr << "Error. Invalid operator." << std::endl;
		return (false);
	}

	_op.push(result);
	return (true);
}

void	RPN::printResult(const char* operation) const {
	std::string str(operation);
	float	result = _op.top();
	std::cout << "\nResult for:\n" << str << " = " << result << std::endl;
}
