#include "Array.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    try {
		unsigned int x = 2;
        Array<std::string> arr(x);

        arr[0] = "Hello";
        arr[1] = "World\n";

        for (size_t i = 0; i < arr.size() + 1; ++i) {
            std::cout << arr[i];
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
