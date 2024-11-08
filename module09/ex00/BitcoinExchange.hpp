#pragma once
#include <map>
#include <iostream>
#include <exception>

class BitcoinExchange {
	public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	bool	onLoadFile(const char *path);

	private:
	std::map<std::string, float>	_prices;

};
