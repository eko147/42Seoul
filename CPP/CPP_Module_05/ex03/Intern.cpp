#include "Intern.hpp"

Intern::Intern(){};

Intern::Intern(const Intern &other){
    *this = other;
}

Intern& Intern::operator=(const Intern &obj){
    (void)obj;
    return (*this);
}

Intern::~Intern(){};

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string str[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for(int i = 0; i < 3; i++){
        if(formName == str[i]){
            std::cout << "Intern creates " << target << std::endl;
            switch (i)
            {
            case 0:
                return new ShrubberyCreationForm(target);
            case 1:
                return new RobotomyRequestForm(target);
            case 2:
                return new PresidentialPardonForm(target);
            }
        }
    }
    std::cout << "Invalid Format Name" << std::endl;
    return NULL;
}