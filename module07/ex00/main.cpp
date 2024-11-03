#include "Whatever.hpp"

template <typename T>
void testSwap(T a, T b) {
	std::cout << "BEFORE SWAP:\t" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "AFTER SWAP:\t" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
}

int main() {
	int a = 2;
	int b = 3;
	testSwap(a, b);

	std::string c = "chaine1";
	std::string d = "chaine2";
	testSwap(c, d);

	return 0;
}
