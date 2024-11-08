#include "Span.hpp"
#include <iostream>
#include <cstdlib>

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
        Span lots = Span(100);
        std::vector<int> many;
        for (int i = 0; i < 100; ++i)
            many.push_back(rand() % 1000);
        lots.addMoreNumbers(many.begin(), many.end());

        std::cout << "Shortest Span: " << lots.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << lots.longestSpan() << std::endl;
        for (size_t i = 0; i < many.size(); i++)
            std::cout << "MANY [IDX] " << i << " : " << many[i] << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}