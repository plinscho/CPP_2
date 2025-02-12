#include "iter.hpp"

void	printInt(int x) {
	std::cout << x << std::endl;
}

template <typename T>
void	printElement(T &element) {
	std::cout << element << std::endl;
}

int main() {

	int arr[] = {0, 1, 2, 3, 4, 5, 6};
	size_t arrLen = (sizeof(arr)/(sizeof(int)));

	std::cout << "Print INT:" << std::endl;
	::iter(arr, arrLen, printElement<int>);

	std::string arrStr[] = {"Hola", "Buenas", "Chao!"};
	size_t arrStrLen = (sizeof(arrStr)/sizeof(arrStr[0]));

	std::cout << "ARR len = " << arrStrLen << std::endl;
	std::cout << "Print Element:" << std::endl;
	::iter(arrStr, arrStrLen, printElement<std::string>);

	return (0);
}