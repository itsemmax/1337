#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"),is_signed(false), gradetosign(100), gradetoexecute(100){}
Form::Form(const std::string name, int gradetosign, int gradetoexecute) : name(name),is_signed(false),gradetosign(gradetosign),gradetoexecute(gradetoexecute){
	if(gradetosign < 1 || gradetoexecute < 1)
		throw GradeTooHighException();
	if(gradetosign > 150 || gradetoexecute > 150)
		throw GradeTooLowException();
}
Form::Form(const Form& other): name(other.name),is_signed(other.is_signed),gradetosign(other.gradetosign),gradetoexecute(other.gradetoexecute){}
Form& Form::operator=(const Form& other){
	if(this != &other)
		is_signed = other.is_signed;
	return *this;
}
Form::~Form(){}
const std::string Form::getName() const{
	return(name);
}
bool Form::getIsSigned() const{
	return(is_signed);
}
int Form::getSignGrade() const{
	return(gradetosign);
}
int Form::getExecuteGrade() const{
	return(gradetoexecute);
}
void Form::beSigned(const Bureaucrat& b){
	if (b.getGrade() <= gradetosign)
		is_signed = true;
	else
		throw Form::GradeTooLowException();
}
const char* Form::GradeTooHighException::what()const throw(){
	return "Grade too high!";
}
const char* Form::GradeTooLowException::what()const throw(){
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form){
	os << "Form Name: " << form.getName() << std::endl
		<< "Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl
		<< "Grade to Sign: " << form.getSignGrade() << std::endl
		<< "Grade to execute: " << form.getExecuteGrade() << std::endl;
		return os;
}
