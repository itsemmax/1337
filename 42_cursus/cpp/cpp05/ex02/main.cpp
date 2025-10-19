#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try{
		Bureaucrat a("A", 5);
		Bureaucrat b("B", 50);
		Bureaucrat c("C", 150);
		ShrubberyCreationForm form1("Home");
		RobotomyRequestForm form2("Marvin");
		PresidentialPardonForm form3("Arthur");

		a.signForm(form1);
		a.signForm(form2);
		a.signForm(form3);
		b.signForm(form1);
		b.signForm(form2);
		b.signForm(form3);
		c.signForm(form1);
		c.signForm(form2);
		c.signForm(form3);

		std::cout << std::endl;

		a.executeForm(form1);
		a.executeForm(form2);
		a.executeForm(form3);
		b.executeForm(form1);
		b.executeForm(form2);
		b.executeForm(form3);
		c.executeForm(form1);
		c.executeForm(form2);
		c.executeForm(form3);

	} catch (std::exception &e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}
    return 0;
}
