#include "PmergeMe.hpp"

int parseArgv(const char* number) {
	
	if (!number) return (-1);
	
	long res = std::atol(number);
	if (res < 0) {
		std::cout << "Error. Only positive integers allowed!" << std::endl;
		return (-1);
	} else if (res > INT_MAX) {
		std::cout << "Error. Integer overflow detected!" << std::endl;
		return (-1);
	}
	return (static_cast<int>(res));
}

int main(int argc, char* argv[]) {
	PmergeMe pm;

	if (argc < 2) {
		std::cout << "Usage: ./PmergeMe 5 4 3 ... " << std::endl;
		return (1);
	}

	for (int i = 1 ; argv[i] != NULL ; i++){
		if (parseArgv(argv[i]) < 0) {
			return (1);
		}
	}
	return (0);
}
