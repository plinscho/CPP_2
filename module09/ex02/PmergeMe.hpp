#pragma once
#include <cstdlib>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <sys/time.h>
#include <ctime>

class PmergeMe {
	public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &rhs);
	~PmergeMe();

	bool	onDuplicates() const ;
	void	addInt(int x);
	void	sortVector();
	void	sortDeque();
	void	mergeInsertionSort(std::vector<int> &arr);
	void	mergeInsertionSort(std::deque<int> &arr);
	void	printVector() const ;
	void	printDeque() const ;
	const std::vector<int> & getVector() const ;
	const std::deque<int> & getDeque() const ;
	
	private:
	std::vector<int>	_Vints;
	std::deque<int>		_Qints;
};