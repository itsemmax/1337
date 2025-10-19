#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"),is_signed(false), gradetosign(100), gradetoexecute(100){}
AForm::AForm(const std::string name, int gradetosign, int gradetoexecute) : name(name),is_signed(false),gradetosign(gradetosign),gradetoexecute(gradetoexecute){
	if(gradetosign < 1 || gradetoexecute < 1)
		throw GradeTooHighException();
	if(gradetosign > 150 || gradetoexecute > 150)
		throw GradeTooLowException();
}
AForm::AForm(const AForm& other): name(other.name),is_signed(other.is_signed),gradetosign(other.gradetosign),gradetoexecute(other.gradetoexecute){}
AForm& AForm::operator=(const AForm& other){
	if(this != &other)
		is_signed = other.is_signed;
	return *this;
}
AForm::~AForm(){}
const std::string AForm::getName() const{
	return(name);
}
bool AForm::getIsSigned() const{
	return(is_signed);
}
int AForm::getSignGrade() const{
	return(gradetosign);
}
int AForm::getExecuteGrade() const{
	return(gradetoexecute);
}
void AForm::beSigned(const Bureaucrat& b){
	if (b.getGrade() <= gradetosign)
		is_signed = true;
	else
		throw AForm::GradeTooLowException();
}
const char* AForm::GradeTooHighException::what()const throw(){
	return "Grade too high!";
}
const char* AForm::GradeTooLowException::what()const throw(){
	return "Grade too low!";
}
const char* AForm::FormNotSignedException::what() const throw(){
	return "Form is not signed!";
}
std::ostream& operator<<(std::ostream& os, const AForm& form){
	os << "Form Name: " << form.getName() << std::endl
		<< "Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl
		<< "Grade to Sign: " << form.getSignGrade() << std::endl
		<< "Grade to execute: " << form.getExecuteGrade() << std::endl;
		return os;
}
