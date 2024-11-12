#pragma once
#include <stack>
#include <cstdlib>
#include <sstream>
#include <iostream>

class RPN {
	public:
	RPN();
	RPN(const RPN &copy);
	RPN &operator=(const RPN &rhs);
	~RPN();

	bool	parseArg(const char *argv);
	bool	performOperation(const std::string &);
	bool	onDigit(const std::string);
	void	loadNumberStack(const std::string);
	void	printResult(const char* ) const ;

	private:
	long double			_result;
	std::stack<float>	_op;
};
