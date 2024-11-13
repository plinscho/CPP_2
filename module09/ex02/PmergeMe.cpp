#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe() {
	_Vints.clear();
	_Qints.clear();
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) {
		_Vints = rhs._Vints;
		_Qints = rhs._Qints;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {

}


const std::vector<int> & PmergeMe::getVector() const {
	return (_Vints);
}

const std::deque<int> & PmergeMe::getDeque() const {
	return (_Qints);
}

void	PmergeMe::addInt(int x) {
	_Vints.push_back(x);
	_Qints.push_back(x);
}

void	PmergeMe::printVector() const {
	for (size_t i = 0 ; i < _Vints.size() ; i++) {
		std::cout << _Vints[i] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printDeque() const {
	for (size_t i = 0 ; i < _Qints.size() ; i++) {
		std::cout << _Qints[i] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::sortVector() {
	mergeInsertionSort(_Vints);
}

void	PmergeMe::sortDeque() {
	mergeInsertionSort(_Qints);
}

bool	PmergeMe::onDuplicates() const {
	for (size_t i = 0 ; i < _Vints.size() ; i++) {
		if (i + 1 < _Vints.size()){
			if (_Vints[i] == _Vints[i + 1]){
				std::cout << "Found duplicate: " << _Vints[i] << std::endl;
				return (true);
			}
		}
	}
	return (false);
}

// FordJohnson algoriths
void	PmergeMe::mergeInsertionSort(std::vector<int> &arr){
	if (arr.size() <= 1) return ;

	std::vector<int> small, big;
	for (size_t i = 0 ; i < arr.size() ; i += 2) {
		if (i + 1 < arr.size()) {
			if (arr[i] < arr[i + 1]) {
				small.push_back(arr[i]);
				big.push_back(arr[i + 1]);
			} else {
				small.push_back(arr[i + 1]);
				big.push_back(arr[i]);
			}
		} else {
			small.push_back(arr[i]);
		}
	}
	mergeInsertionSort(small);
	mergeInsertionSort(big);

	std::merge(small.begin(), small.end(), big.begin(), big.end(), arr.begin());
}

void	PmergeMe::mergeInsertionSort(std::deque<int> &arr){
	if (arr.size() <= 1) return ;

	std::deque<int> small, big;
	for (size_t i = 0 ; i < arr.size() ; i += 2) {
		if (i + 1 < arr.size()) {
			if (arr[i] < arr[i + 1]) {
				small.push_back(arr[i]);
				big.push_back(arr[i + 1]);
			} else {
				small.push_back(arr[i + 1]);
				big.push_back(arr[i]);
			}
		} else {
			small.push_back(arr[i]);
		}
	}
	mergeInsertionSort(small);
	mergeInsertionSort(big);

	std::merge(small.begin(), small.end(), big.begin(), big.end(), arr.begin());
}
