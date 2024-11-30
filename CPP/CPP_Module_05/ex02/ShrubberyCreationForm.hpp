#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
    void createShrubberyFile() const;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string _target);
    ShrubberyCreationForm(const ShrubberyCreationForm &obj);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &obj);
    virtual ~ShrubberyCreationForm();

    std::string getTarget() const;
    void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &ShrubberyCreationForm);

#endif 