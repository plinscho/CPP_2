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

	bool	onLoadData(const char *path);
	bool	onParseFile(const char* fileName) const ;
	float	getRate(const std::string &) const ;

	private:
	std::map<std::string, float>	_prices;

};

bool		validateDate(std::string &date);
float		strToFloat(std::string &valueFloat);

void		printString(const char* string);
std::string	trimString(const std::string &str);
