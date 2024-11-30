#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("name"), _grade(150){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if(_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (this != &obj){
        this->_grade = obj._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(){}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    } 
    catch (const Form::GradeTooLowException& e) {
        std::cerr << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const std::string Bureaucrat::getName() const 
{
    return(_name);
}

int Bureaucrat::getGrade() const
{
    return(_grade);
}

void Bureaucrat::incrementGrade()  {
	if (_grade == 1)
		throw GradeTooHighException();
	std::cout << "Grade has increased successfully." << std::endl;
	--_grade;
}

void Bureaucrat::decrementGrade()   {
	if (_grade == 150)
		throw GradeTooLowException(); 
	std::cout << "Grade has lowered successfully." << std::endl;
	++_grade;
}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return (os);
}