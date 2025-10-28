#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Span {
	private:
		unsigned int N;
		std::vector<int> vec;
	public:
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;
		
		template <typename it>
		void addNumber(it begin, it end){
			size_t distance = std::distance(begin, end);
				if (vec.size() + distance > N)
					throw std::runtime_error("cannot add more numbers, capacity exceeded");
			vec.insert(vec.end(), begin, end);
		}
		
};

#endif