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

// Argument to test 3000 different positive ints:
// ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
int main(int argc, char* argv[]) {
	PmergeMe pm;

	if (argc < 2) {
		std::cout << "Usage: ./PmergeMe 5 4 3 ... " << std::endl;
		return (1);
	}

	int num = 0;
	for (int i = 1 ; argv[i] != NULL ; i++){
		num = parseArgv(argv[i]);
		if (num < 0) {
			return (1);
		}
		pm.addInt(num);
	}

	std::cout << "Before: ";
	pm.printVector();

	// merge sort vector ints
	clock_t start = clock();
	pm.sortVector();
	clock_t end = clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	
	if (pm.onDuplicates()) {
		std::cout << "Error. There are duplicate numbers!" << std::endl;
		return (1);
	}
	std::cout << "After: ";
	pm.printVector();
	std::cout << "Time to process a range of " << pm.getVector().size() 
	<< " elements with std::vector is: " << duration << "ms" << std::endl;

	start = clock();
	pm.sortDeque();
	end = clock();
	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;	
	std::cout << "Time to process a range of " << pm.getDeque().size() 
	<< " elements with std::deque is: " << duration << "ms" << std::endl;

	return (0);
}
