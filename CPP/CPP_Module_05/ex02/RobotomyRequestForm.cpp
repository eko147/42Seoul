#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm():  AForm("default", 72, 45), _target("default"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), _target(obj._target) {*this = obj;}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj){
    if (this != &obj){
        this->_target = obj._target;}
    return (*this);}

RobotomyRequestForm::~RobotomyRequestForm(){}

std::string RobotomyRequestForm::getTarget() const {
    return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if(this->getIsSigned() == false){
        throw AForm::SignedException();
    }
    else if (executor.getGrade() > this->getGradeToExecute()){
        throw AForm::GradeTooLowException();
    }
    else{
        std::srand(std::time(NULL));
        std::cout << "Drilling..." << std::endl;
        (std::rand() % 2 == 0) ?
        std::cout << this->_target << " has been robotomized successfully" << std::endl :
        std::cout << this->_target << " has been robotomization failed" << std::endl;
    }
}
