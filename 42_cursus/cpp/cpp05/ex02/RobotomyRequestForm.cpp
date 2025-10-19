#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	static int counter = 0;
	if (!getIsSigned()) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getExecuteGrade()) {
		throw AForm::GradeTooLowException();
	}
	if (counter++ % 2){
		std::cout << "Brrrrrrr..." << std::endl;
		std::cout << target << " has been robotomized successfully!" << std::endl;
	}
	else
			std::cout << "The robotomy failed!" << std::endl;
	std::cout << "Drilling noises... " << target << std::endl;
}