#include "Array.hpp"

int main(){
	Array<int> arr;
	std::cout << "Size of empty array: " << arr.size() << std::endl;

	Array<int> arr1(5);
	for (size_t i = 0; i < arr1.size(); ++i) {
		arr1[i] = i * 10;
	}
	for (size_t i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << std::endl;
	}

	Array<std::string> arr3(3);
	arr3[0] = "emma";
	arr3[1] = "test";
	arr3[2] = "hola";
	for (size_t i = 0; i < arr3.size(); ++i) {
		std::cout << arr3[i] << std::endl;
	}
	try {
		std::cout << arr1[10] << std::endl;
	}catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}