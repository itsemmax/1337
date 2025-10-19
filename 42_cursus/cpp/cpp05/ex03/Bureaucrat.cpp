#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}
Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other)
		this->grade = other.grade;
	return *this;
}
Bureaucrat::~Bureaucrat(){}

const std::string Bureaucrat::getName() const{
	return this->name;
}
int Bureaucrat::getGrade() const{
	return this->grade;
}

void Bureaucrat::incrementGrade(){
	if (this->grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	--this->grade;
}

void Bureaucrat::decrementGrade(){
	if (this->grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	++this->grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}
void Bureaucrat::signForm(AForm& form){
	try{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}catch(std::exception &e){
		std::cerr << this->name << " cannot sign "
			<< form.getName() << " because: " << e.what() << std::endl;
	}
}
void Bureaucrat::executeForm(AForm const& form) {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}