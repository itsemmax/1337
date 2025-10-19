#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string name;
	bool is_signed;
	const int gradetosign;
	const int gradetoexecute;
public:
	AForm();
	AForm(const std::string name, int gradetosign, int gradetoexecute);
	AForm(const AForm& other);
	virtual ~AForm();
	AForm& operator=(const AForm& other);
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
	class FormNotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};
	virtual void execute(const Bureaucrat& executor) const = 0;
};
std::ostream& operator<<(std::ostream& os, const AForm& form);
#endif