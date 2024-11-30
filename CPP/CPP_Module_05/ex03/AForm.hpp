#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
class Bureaucrat;

class AForm { 
private:
    const std::string _name;
    bool _signedStatus;
    const int _gradeToSign;
    const int _gradeToExecute;

public:

    /*Orthodox Canonical Form*/
    AForm();
    AForm(const AForm &other);
    AForm& operator=(const AForm &obj);
    virtual ~AForm();

    AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class SignedException : public std::exception{
	public:
		const char* what(void) const throw();
	};

    /*Getter*/
    const std::string getName() const; 
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    /*Methods*/
    void beSigned(Bureaucrat const & bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
