#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

class Span {
	public:
		Span(unsigned int maxN);
		Span(const Span &copy);
		Span &operator=(const Span &rhs);
		~Span();

		void	addNumber(int n);
		void	addMoreNumbers(std::vector<int>::iterator, std::vector<int>::iterator);
		int		shortestSpan() const ;
		int		longestSpan() const ;
		bool	hasNumbers() const ;
	
	private:
		unsigned int 		_maxN;
		std::vector<int>	_numbers;
};
