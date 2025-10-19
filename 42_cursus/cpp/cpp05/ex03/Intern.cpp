#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}


AForm *Intern::makeForm(const std::string& name, const std::string& target) {
	std::string str[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm    *ptr[3];
	ptr[0] = new PresidentialPardonForm(target);
	ptr[1] = new RobotomyRequestForm(target);
	ptr[2] = new ShrubberyCreationForm(target);

	for (int i = 0; i < 3; i++)
	{
		if(str[i] == name)
		{
			std::cout << "Intern creates " << str[i] << std::endl;
			for(int k = 0; k < 3; k++)
			{
				if(k != i)
					delete ptr[k];
			}
			return ( ptr[i]);
		}
	}
	std::cout << name << " form doesnt exist!" << std::endl;
	for(int k = 0; k < 3; k++)
		delete ptr[k];
	return(NULL);
}