#pragma once
#include <cstdlib>
#include <climits>
#include <iostream>
#include <vector>

class PmergeMe {
	public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &rhs);
	~PmergeMe();
	
	private:
	std::vector<int>	_Vints;
};