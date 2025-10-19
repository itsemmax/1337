#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
private:
	const std::string name;
	bool is_signed;
	const int gradetosign;
	const int gradetoexecute;
public:
	Form();
	Form(const std::string name, int gradetosign, int gradetoexecute);
	Form(const Form& other);
	~Form();
	Form& operator=(const Form& other);
	const std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	void beSigned(const Bureaucrat& b);
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};
std::ostream& operator<<(std::ostream& os, const Form& form);
#endif