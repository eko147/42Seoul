#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

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
    std::string getName() const;
    int getGrade() const;
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