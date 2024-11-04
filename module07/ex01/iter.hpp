#pragma once
#include <iostream>

template <typename T, typename F>
void	iter(T *addr, size_t &lenArray, F function) {
	for (size_t i = 0 ; i < lenArray ; ++i) {
		function(addr[i]);
	}
}
