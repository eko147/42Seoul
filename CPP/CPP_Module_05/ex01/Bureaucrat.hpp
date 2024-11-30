#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <string>
#include <iostream>
class Form;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    /*Orthodox Canonical Form*/
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat &obj);
    Bureaucrat(std::string name, int grade);

    
    /*fuctions*/
    void signForm(Form& form);
    const std::string getName() const;
    int getGrade() const ;
    void incrementGrade();
    void decrementGrade();

  class GradeTooHighException : public std::exception
	{
		public:
		  const char * what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		  const char * what() const throw();
	};

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
