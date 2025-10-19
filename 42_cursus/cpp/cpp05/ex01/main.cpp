#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try{
		Bureaucrat a("A", 5);
		Bureaucrat b("B", 50);

		Form form1("Form A",10,20);
		Form form2("Form B",100,150);

		a.signForm(form1);
		a.signForm(form2);
		b.signForm(form1);
		b.signForm(form2);

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		
	} catch (std::exception &e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}
    return 0;
}
