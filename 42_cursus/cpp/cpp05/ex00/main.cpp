#include "Bureaucrat.hpp"

int main(){
	try {
		Bureaucrat a("A", 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat b("B", 149);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}