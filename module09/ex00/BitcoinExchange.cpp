#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <fstream>

#define BAD_INPUT "Error: bad input => "

BitcoinExchange::BitcoinExchange() {
	_prices.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		_prices.clear();
		_prices = rhs._prices;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {

}

// UTILS

void	printString(const char* string) {
	std::cout << string << std::endl;
}

std::string	trimString(const std::string &str) {
	size_t first = str.find_first_not_of(" ");
	size_t last = str.find_last_not_of(" ");
	return (str.substr(first, last - first + 1));
}

static bool	isDigitStr(const std::string &str) {
	return (str.find_first_not_of("0123456789") == std::string::npos);
}

// #######################################################################

float	BitcoinExchange::getRate(const std::string &date) const {
	std::map<std::string, float>::const_iterator it;

	it = _prices.lower_bound(date);
	if (it == _prices.end() || it->first != date) {
		if (it == _prices.begin()) {
			return (0);
		}
		--it;
	}
	return (it->second);
}

bool	BitcoinExchange::onLoadData(const char* path) {
	if (!path) {
		printString("Error. Path not found!");
		return (false);
	}
	
	std::ifstream file(path);
	if (!file.is_open()) { 
		printString("Error. File cold not be loaded!");
		return (false);
	} 

	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		float		value;

		//	Saves into "date" the content until ',' is found. 
		//	Also saves the content after in "value"
		if (std::getline(ss, date, ',') && ss >> value) {
			_prices[date] = value;
		}
	}
	file.close();
	printString("Data loaded from \"data.csv\".\nClosing file.");
	return (true);
}

bool	validateDate(std::string &date) {
	if (date.empty()) {
		return (false);
	}

	std::stringstream	ss(date);
	std::string			field;
	int					year, month, day;

	getline(ss, field, '-'); // append the year into field
	if (field.length() != 4 || !isDigitStr(field)) {
		return (false);
	}
	year = static_cast<int>(std::atof(field.c_str()));

	getline(ss, field, '-'); //	append the month
	if (!isDigitStr(field)) {
		return (false);
	}
	month = static_cast<int>(std::atof(field.c_str()));

	field = date.substr(date.find_last_of('-') + 1, date.length());
	if (!isDigitStr(field)) {
		return (false);
	}
	day = static_cast<int>(std::atof(field.c_str()));

	if (day < 1 || day > 31) {
        return (false);
	}
    else if (month < 1 || month > 12) {
        return (false);
	}
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
        return (false);
    else if ((month == 2) && (year % 4 == 0) && day > 29)
        return (false);
    else if ((month == 2) && (year % 4 != 0) && day > 28)
        return (false);
    return (true);
}

float	strToFloat(std::string &valueFloat) {
	std::stringstream ss(valueFloat);
	float	value;

	ss >> value;
	if (ss.fail()) {
		throw std::invalid_argument("Error. Invalid float format");
	}
	return (value);
}

bool	BitcoinExchange::onParseFile(const char* fileName) const {
	std::ifstream file(fileName);

	if (!file.is_open()) {
		printString("Error. Could not open file");
		return (false);
	}

	// Load the content from the file
	bool		firstLine = true;
	std::string line;
	while (std::getline(file, line)) {

		if (line.empty()) {
			continue;
		} else if (firstLine) {
			// skipping the first line
			firstLine = false; 
			continue;
		}

		std::istringstream	inputLine(line);
		std::string			date, valueStr;
		if (!std::getline(inputLine, date, '|') || !std::getline(inputLine, valueStr)) {
			std::cerr << BAD_INPUT << line << std::endl;
			continue;
		}

		date = trimString(date);
		valueStr = trimString(valueStr);

		try {
			if (!validateDate(date)) {
				throw std::invalid_argument(BAD_INPUT);
			}
			float value = strToFloat(valueStr);
			if (value < 0) {
				throw std::invalid_argument("Error. Not a positive number => ");
			} else if (value > 1000) {
				throw std::invalid_argument("Error. Number too large => ");
			}

			// print the price for the date
			float rate = getRate(date);
			std::cout << date << " => " << value << " = " << value * rate << std::endl;

		} catch (const std::exception &e) {
			std::cerr << e.what() << line << std::endl;
		}

	}
	printString("Done!");
	file.close();
	return (true);
}



