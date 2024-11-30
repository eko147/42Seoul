#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _signedStatus;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    /*Orthodox Canonical Form*/
    Form();
    Form(const Form &other);
    Form& operator=(const Form &obj);
    ~Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);

    /*functions*/
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    bool getIsSigned() const ;
    const std::string& getName() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif