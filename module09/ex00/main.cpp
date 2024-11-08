#include "BitcoinExchange.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>

bool	onOpenFile(const char* path) {
	if (!path) return (false);

	std::ifstream inputFile(path);
	if (!inputFile.is_open()) {
		return (false);
	}
	inputFile.close();
	return (true);
}

void	closeFile() {

}

int main(int argc, char* argv[]) {
	
	if (argc > 2) {
		std::cout << "Error, 2 arguments expected." << std::endl;
		return (1);
	} else if (!onOpenFile(argv[1])) {
		std::cerr << "Error. File not found!" << std::endl;
		return (1);
	}
	

	return (0);
}
