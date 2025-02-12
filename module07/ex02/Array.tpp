#include "Array.hpp"
#include <cstring>

template <typename T>
Array<T>::Array() {
	_data = NULL;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int size) : _size(size) {
	_data = new T[size]();
}

template <typename T>
Array<T>::~Array() {
	if (_data)
		delete [] _data;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs) {
	if (this != &rhs){
		if (_data)
			delete [] _data;
		_size = rhs.size();
		if (_size > 0) {
			_data = new T[_size];
			std::memcpy(_data, rhs._data, _size * sizeof(T));
		} else {
			_data = NULL;
		}
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](size_t index) {
	if (!_data) {
		throw std::invalid_argument("Error. Array not found!");
	} else if (index >= size()) {
		throw std::range_error("Error. Out of bounds");
	}
	return _data[index];
}

template <typename T>
Array<T>::Array(const Array &copy)
: _size(copy.size()), _data(NULL) {
	if (_size > 0) {
		_data = new T[_size];
		std::memcpy(_data, copy._data, _size * sizeof(T));
	}
}

template <typename T>
size_t	Array<T>::size() const {
	return _size;
}
