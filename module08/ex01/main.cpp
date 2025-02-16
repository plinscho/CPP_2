#include "Span.hpp"
#include <iostream>
#include <cstdlib>

void    printArr(std::vector<int>arr) {
    for (size_t i = 0; i < arr.size(); i++)
    std::cout << "MANY [IDX] " << i << " : " << arr[i] << std::endl;
}

#define MAX_LEN 100000
int main() {
    try {
        std::cout << "SUBJECT TEST" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::cout << "SUBJECT TEST END" << std::endl;

        std::cout << "MANY TEST" << std::endl;
		srand((int) time(NULL));
        Span lots = Span(MAX_LEN);
        std::vector<int> many;
        for (int i = 0; i < MAX_LEN ; ++i)
            many.push_back(rand() % 1000000);
        lots.addMoreNumbers(many.begin(), many.end());

        std::cout << "Shortest Span: " << lots.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << lots.longestSpan() << std::endl;

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}