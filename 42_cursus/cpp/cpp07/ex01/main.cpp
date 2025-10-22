#include "iter.hpp"

template<typename T>

void print(T a) {
	std::cout << a << std::endl;
}

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6};
	iter(arr, 6, print<int>);

	std::string strArr[] = {"Hello", "World", "emma"};
	iter(strArr, 3, print<std::string>);
	return 0;
}
