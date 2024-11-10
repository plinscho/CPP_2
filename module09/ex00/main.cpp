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
	printString("File found. Loading.");
	return (true);
}

void	closeFile() {

}

int main(int argc, char* argv[]) {
	BitcoinExchange bc;

	if (argc > 2) {
		std::cout << "Error, 2 arguments expected." << std::endl;
		return (1);
	} else if (!onOpenFile(argv[1])) {
		std::cerr << "Error. File not found!" << std::endl;
		return (1);
	}

	if (!bc.onLoadData("data.csv")){
		return (1);
	}
	
	bc.onParseFile(argv[1]);
	
	return (0);
}
