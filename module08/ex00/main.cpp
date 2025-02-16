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
            vect[i] = rand() % MAX_LEN;
            std::cout << " " << vect[i];
        }
        std::cout << std::endl;

        std::vector<int> myvect(MAX_LEN);
        for (size_t i = 0; i < myvect.size(); ++i)
            myvect[i] = vect[i];
        int needle = easyfind(myvect, 10);
        std::cout << "NEEDLE: " << needle << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}