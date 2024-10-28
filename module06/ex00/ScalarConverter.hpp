#pragma once
#include <iostream>

enum fmtType {
	SPECIAL = 0, 
	CHAR, 
	INT, 
	FLOAT, 
	DOUBLE, 
	NOT_VALID
};

typedef struct s_val {
	std::string	raw;
	char		valC;
	int			valI;
	float		valF;
	double		valD;
} Values;

class ScalarConverter {
	public:
	static void	convert(const std::string &);

	private:
};

void	printSpecials(const std::string &);
