#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():  AForm("default", 25, 5), _target("default"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj), _target(obj._target) {*this = obj;}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj){
    if (this != &obj){
        this->_target = obj._target;}
    return (*this);}

PresidentialPardonForm::~PresidentialPardonForm(){}

std::string PresidentialPardonForm::getTarget() const {
    return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if(this->getIsSigned() == false){
        throw AForm::SignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()){
        throw AForm::GradeTooLowException();
    }
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


