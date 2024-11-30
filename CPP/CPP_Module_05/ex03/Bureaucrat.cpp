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


void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this); 
        std::cout << getName() << " signed " << form.getName() << std::endl;
    } 
    catch (const AForm::GradeTooLowException& e) { 
        std::cerr << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }

}
void Bureaucrat::executeForm(AForm const &form) {
    try {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    } 
    catch (const AForm::GradeTooLowException& e) {
        std::cerr << getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
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

const char* Bureaucrat::GradeTooHighException::what() const throw() { //예외명세
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) // const로 들어와서 메서드도 const인 함수만 가능
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return (os);
}