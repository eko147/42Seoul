#include "AForm.hpp"

AForm::AForm()
    : _name("default"), _signedStatus(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute)
    : _name(name), _signedStatus(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {}

AForm::AForm(const AForm &obj)
	: _name(obj._name),_signedStatus(obj._signedStatus), _gradeToSign(obj._gradeToSign),_gradeToExecute(obj._gradeToExecute) {}

AForm &AForm::operator=(const AForm &obj){
    if (this != &obj){
        this->_signedStatus = obj._signedStatus;}
    return (*this);}

AForm::~AForm(){}

/*Methods*/

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::SignedException::what() const throw() {
    return "Form is not signed!";
}

void AForm::beSigned(Bureaucrat const & bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw Bureaucrat::GradeTooLowException();}
    _signedStatus = true;
}

/*Getter*/

const std::string AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _signedStatus;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "Form: " << form.getName()
        << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", GradeToSign: " << form.getGradeToSign()
        << ", GradeToExecute: " << form.getGradeToExecute();
    return os;
}