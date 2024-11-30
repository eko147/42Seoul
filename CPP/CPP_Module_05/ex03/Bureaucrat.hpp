#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    /*Orthodox Canonical Form*/
    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat &obj);
    ~Bureaucrat();
    Bureaucrat(std::string name, int grade);

    
    /*fuctions*/
    void signForm(AForm& form);
    void executeForm(AForm const &form);
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
