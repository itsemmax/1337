#include <iostream>
#include <string>
class emma{
	public:
		static void print(){
			std::cout << "hello\n";
		}
};
int main()
{
	// std::string h[2] = {"test", "Hello"};
	// std::string *str = h;
	// std::cout << str[0] << std::endl; 

	// char *str2 = {"1a", "2b"};
	// std::cout << str2[0] << std::endl;
	// std::string str = "hello";
	// char *arr[] = {"hello","emma", "ilyass"};
	// char **str1 = arr;
	// std::string arr[] = {"hello", "emma"};
	// std::string *str = arr;
	// std::cout << str[1] << std::endl;

	// char *t = "Hello";
	// std::string* str(t); // String (char pointer)

    // std::cout << str << std::endl;

	// std::string *str = "hello";
	// emma assia;
	emma::print();

}