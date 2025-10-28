#include "Span.hpp"

Span::Span(unsigned int n) : N(n) {}
Span::Span(const Span& other) : N(other.N), vec(other.vec) {}
Span& Span::operator=(const Span& other) {
	if (this != &other) {
		N = other.N;
		vec = other.vec;
	}
	return *this;
}
Span::~Span() {}
void Span::addNumber(int n) {
	if (vec.size() >= N)
		throw std::runtime_error("cannot add more numbers, capacity exceeded");
	vec.push_back(n);
}

int Span::shortestSpan() const {
	if (vec.size() < 2)
		throw std::runtime_error("not enough numbers to find a span");
	std::vector<int> sortedvec = vec;
	std::sort(sortedvec.begin(), sortedvec.end());
	int minSpan = sortedvec[1] - sortedvec[0];
	for (size_t i = 1; i < sortedvec.size() - 1; ++i) {
		int span = sortedvec[i + 1] - sortedvec[i];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}
int Span::longestSpan() const {
	if (vec.size() < 2)
		throw std::runtime_error("not enough numbers to find a span");
	std::vector<int> sortedvec = vec;
	std::sort(sortedvec.begin(), sortedvec.end());
	return sortedvec.back() - sortedvec.front();
}
