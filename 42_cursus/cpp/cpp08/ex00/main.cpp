#include "easyfind.hpp"
#include <vector>
#include <list>

int main(){
	std::vector<int> vector;
	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	vector.push_back(40);
	try{
		std::vector<int>::iterator it = easyfind(vector, 20);
		std::cout << "Found value: " << *it << std::endl;
		it = easyfind(vector, 100);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch(const std::runtime_error& e){
		std::cerr << e.what() << std::endl;
	}
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	try{
		std::list<int>::iterator it = easyfind(lst, 3);
		std::cout << "Found value: " << *it << std::endl;
		it = easyfind(lst, 5);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch(const std::runtime_error& e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}