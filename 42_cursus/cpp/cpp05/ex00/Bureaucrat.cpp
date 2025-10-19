#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}
Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	grade = grade;
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
		this->grade--;
		if (this->grade > 150)
			throw Bureaucrat::GradeTooLowException();
		if (this->grade < 1)
			throw Bureaucrat::GradeTooHighException();
	}

	void Bureaucrat::decrementGrade(){
		this->grade++;
		if (this->grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (this->grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}

	const char* Bureaucrat::GradeTooHighException::what() const throw(){
		return "Grade is too high!";
	}

	const char* Bureaucrat::GradeTooLowException::what() const throw(){
		return "Grade is too low!";
	}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}