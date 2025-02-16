#pragma once
#include <iostream>
#include <exception>
#include <algorithm>

template <typename T>
int	easyfind(T haystack, int needle) {
	typename T::iterator id = find(haystack.begin(), haystack.end(), needle);
	if (id != haystack.end()) {
		return *id;
	} else {
		throw std::range_error("Error, needle not found");
	}
}
