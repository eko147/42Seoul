#include "Form.hpp"

Form::Form()
    : _name("default"), _signedStatus(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute)
    : _name(name), _signedStatus(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

Form::Form(const Form &obj)
	: _name(obj._name),_signedStatus(obj._signedStatus), _gradeToSign(obj._gradeToSign),_gradeToExecute(obj._gradeToExecute) {}

Form &Form::operator=(const Form &obj){
    if (this != &obj){
        this->_signedStatus = obj._signedStatus;}
    return (*this);}

Form::~Form() {}

/*Getters*/

const std::string& Form::getName() const{
    return _name;
}

bool Form::getIsSigned() const{
    return _signedStatus;
}

int Form::getGradeToSign() const{
    return _gradeToSign;
}

int Form::getGradeToExecute() const{
    return _gradeToExecute;
}

/*Methods*/

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _gradeToSign) {
        _signedStatus = true;
        std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
    }
    else {
        throw GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

/*Overload*/

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName()
    << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
    << ", GradeToSign: " << form.getGradeToSign()
    << ", GradeToExecute: " << form.getGradeToExecute();
    return os;
}
