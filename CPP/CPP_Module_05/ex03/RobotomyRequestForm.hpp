#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string _target);
    RobotomyRequestForm(const RobotomyRequestForm &obj);
    RobotomyRequestForm& operator=(const RobotomyRequestForm &obj);
    virtual ~RobotomyRequestForm();

    std::string getTarget() const;
    void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &RobotomyRequestForm);

#endif