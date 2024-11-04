#pragma once
#include <iostream>
#include <exception>

template <typename T> class Array {
	public:
	Array();
	Array(unsigned int &n);
	~Array();
	Array &operator=(const Array &);
	T &operator[](size_t index);
	Array(const Array &copy);

	size_t	size() const ;

	private:
	size_t	_size;
	T		*_data;
};

#include "Array.tpp"
