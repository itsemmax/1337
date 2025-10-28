#include "Span.hpp"


int main(){
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try {
	Span a(4);
	a.addNumber(7);
	a.addNumber(4);
	a.addNumber(9);
	a.addNumber(1);
	std::cout << "Shortest Span: " << a.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << a.longestSpan() << std::endl;
	a.addNumber(20);
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Span b(10000);
		for (int i = 0; i < 10000; ++i) {
			b.addNumber(i);
		}
		std::cout << "Shortest Span in large Span: " << b.shortestSpan() << std::endl;
		std::cout << "Longest Span in large Span: " << b.longestSpan() << std::endl;
		b.addNumber(10001);
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
	try{
		Span c(12);
		c.addNumber(10);
		c.addNumber(20);
		std::vector<int> numbers;
		for (int i = 0; i < 10; ++i) {
			numbers.push_back(i);
		}
		c.addNumber(numbers.begin(), numbers.end());
		std::cout << "Shortest Span with sufficient numbers: " << c.shortestSpan() << std::endl;
		std::cout << "Longest Span with sufficient numbers: " << c.longestSpan() << std::endl;
		c.addNumber(5);
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}
}