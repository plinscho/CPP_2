#pragma once
#include <iostream>
#include <exception>
#include <algorithm>

template <typename T>
void	easyfind(T haystack, int needle) {
	typename T::iterator it;
	int i = 0;
	for (it = haystack.begin() ; it != haystack.end() ; it++) {
		if (*it == needle) {
			std::cout << "Found needle: " << *it << "\nIn position: " << i << std::endl;
			return ;
		}
		i++;
	}
	throw std::range_error("Error, needle not found");
}
