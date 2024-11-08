#include "Span.hpp"

Span::Span(unsigned int maxN) : _maxN(maxN) {
	_numbers.clear();
}

Span::Span(const Span &copy) {
	if (this != &copy) {
		*this = copy;
	}
}

Span &Span::operator=(const Span &rhs) {
	_maxN = rhs._maxN;
	_numbers.clear();
	int size = rhs._numbers.size();
	for (int i = 0 ; i < size ; i++) {
		_numbers[i] = rhs._numbers[i];
	}
	return (*this);
}

Span::~Span() {
	_numbers.clear();
}

bool	Span::hasNumbers() const {
	return (_numbers.size() > 0 ? true : false);
}

void	Span::addNumber(int n) {
	if (_numbers.size() < _maxN) {
		_numbers.push_back(n);
	} else {
		std::cerr << "Error. Span is full." << std::endl;
	}
}

void	Span::addMoreNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	std::vector<int>::iterator it = first;
	for (; it != last ; it++) {
		addNumber(*it);
	}
}


int	Span::shortestSpan() const {
	if (!hasNumbers()) return (0);
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (unsigned int i = 1; i < tmp.size(); i++) {
        if (tmp[i] - tmp[i - 1] < min)
            min = tmp[i] - tmp[i - 1];
    }
    return (min);
}

int	Span::longestSpan() const {
	if (!hasNumbers()) return (0);
	int min = *min_element(_numbers.begin(), _numbers.end());
	int max = *max_element(_numbers.begin(), _numbers.end());
	return (max - min);
}
