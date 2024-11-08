#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>

BitcoinExchange::BitcoinExchange() {
	_prices.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {

}

BitcoinExchange::~BitcoinExchange() {

}

bool	BitcoinExchange::onLoadFile(const char* path) {
	if (!path) return (false);
	
	std::ifstream file(path);
	if (!file.is_open()) return (false);

	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		float		value;

		if (std::getline(ss, date, ',') && ss >> value) {
			_prices[date] = value;
		}
	}
	file.close();
}



