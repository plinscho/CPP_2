#include "easyfind.hpp"
#include <vector> // std::vector

int main() {
    try {
        int vect[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        std::vector<int> myvect(10);
        for (size_t i = 0; i < myvect.size(); ++i)
            myvect[i] = vect[i];
        easyfind(myvect, 10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}