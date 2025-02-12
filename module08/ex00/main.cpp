#include "easyfind.hpp"
#include <vector> // std::vector
#include <cstdlib>
#include <ctime>


#define MAX_LEN 100
int main() {
    srand(time(NULL));
    try {
        int vect[MAX_LEN];
        for (int i = 0 ; i < MAX_LEN ; i++) {
            vect[i] = rand() % 100;
            std::cout << " " << vect[i];
        }
        std::cout << std::endl;

        std::vector<int> myvect(MAX_LEN);
        for (size_t i = 0; i < myvect.size(); ++i)
            myvect[i] = vect[i];
        easyfind(myvect, 2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}