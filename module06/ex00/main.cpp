#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[]) {

	if (argc != 2){
		std::cerr << "Error. 2 arguments required." << std::endl;
		return (1);
	}
	std::cout << "INPUT: " << argv[1] << std::endl;
	ScalarConverter::convert(argv[1]);
	return (0);
}