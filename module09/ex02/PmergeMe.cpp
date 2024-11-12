#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {

}



