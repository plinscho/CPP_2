#pragma once
#include <iostream>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
	public:
	MutantStack() {};
	MutantStack(const MutantStack &copy) : std::stack<T>(copy) {};
	MutantStack &operator=(const MutantStack &rhs) {
		this->c = rhs.c;
		return (*this);
	};
	~MutantStack(){};

	typedef typename std::deque<T>::iterator iterator;
	iterator	begin() { return this->c.begin(); }
	iterator	end() { return this->c.end(); }
};
