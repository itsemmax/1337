#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
private:
	T* arr;
	size_t length;
public:
	Array() : arr(NULL), length(0) {}

	Array(unsigned int n) : length(n) {
		arr = new T[length]();
	}

	Array(const Array& other) : length(other.length) {
		arr = new T[length];
		for (size_t i = 0; i < length; ++i) {
			arr[i] = other.arr[i];
		}
	}

	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] arr;
			length = other.length;
			arr = new T[length];
			for (size_t i = 0; i < length; ++i) {
				arr[i] = other.arr[i];
			}
		}
		return *this;
	}

	~Array() {
		delete[] arr;
	}

	size_t size() const {
		return length;
	}

	T& operator[](size_t index) {
		if (index >= length) {
			throw std::exception();
		}
		return arr[index];
	}

	const T& operator[](size_t index) const {
		if (index >= length) {
			throw std::exception();
		}
		return arr[index];
	}
};

#endif