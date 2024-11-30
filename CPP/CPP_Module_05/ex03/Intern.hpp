#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern 
{
private:
public:
    Intern();
    Intern(const Intern &other);
    Intern& operator=(const Intern &obj);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif