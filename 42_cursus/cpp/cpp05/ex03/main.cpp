#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Intern intern;

    AForm* form1 = intern.makeForm("ShrubberyCreationForm", "Home");
    AForm* form2 = intern.makeForm("RobotomyRequestForm", "R2D2");
    AForm* form3 = intern.makeForm("PresidentialPardonForm", "Marvin");

    AForm* form4 = intern.makeForm("invalid form", "Target");

    delete form1;
    delete form2;
    delete form3;
    delete form4;

    return 0;
}

