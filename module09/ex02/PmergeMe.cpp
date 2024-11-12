#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe() {
	_Vints.clear();
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) {
		_Vints = rhs._Vints;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {

}



