#pragma once
#include <iostream>

#define IMPOSSIBLE 0x00000001

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
    ScalarConverter(void);
    ~ScalarConverter(void);
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
};

void	printSpecials(const std::string &);
