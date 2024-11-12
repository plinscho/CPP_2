#include "RPN.hpp"
#include <iostream>



int main(int argc, char* argv[]) {

	RPN rpn;

	if (argc != 2) {
		std::cout << "Error.\nUsage: ./RPN [notation]" << std::endl;
		return (1);
	}
	if (!rpn.parseArg(argv[1])) return (1);
	rpn.printResult(argv[1]);
	return (0);
}