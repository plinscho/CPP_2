#include "Array.hpp"
#include <cstring>

template <typename T>
Array<T>::Array() {
	_data = NULL;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int &size) : _size(size) {
	_data = new T[size];
}

template <typename T>
Array<T>::~Array() {
	delete [] _data;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs) {
	if (this != &rhs){
		delete [] _data;
		_size = rhs.size();
		_data = new T[_size];
		std::memcpy(_data, rhs._data, _size * sizeof(T));
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](size_t index) {
	if (_data) {
		throw std::invalid_argument("Error. Array not found!");
	} else if (index >= size()) {
		throw std::range_error("Error. Out of bounds");
	}
	return _data[index];
}

template <typename T>
Array<T>::Array(const Array &copy) {
	if (this != &copy) {
		*this = copy;
	}
}

template <typename T>
size_t	Array<T>::size() const {
	return _size;
}
