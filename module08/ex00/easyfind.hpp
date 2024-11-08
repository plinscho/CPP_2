#pragma once
#include <iostream>
#include <exception>
#include <algorithm>

template <typename T>
void	easyfind(T haystack, int needle) {
	typename T::iterator it;
	it = std::find(haystack.begin(), haystack.end(), needle);
	if (it == haystack.end()) {
		throw std::range_error("Error, needle not found");
	} else {
		std::cout << "Found at position: " << *it << std::endl;
	}
}
