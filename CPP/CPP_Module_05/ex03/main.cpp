#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
    
    try {
        Intern Intern;
        AForm* rrf;
        rrf = Intern.makeForm("shrubbery creation", "Factory");

        Bureaucrat bureaucrat("Romy", 45);
        bureaucrat.signForm(*rrf);
        bureaucrat.executeForm(*rrf);

        delete rrf;
    } catch (std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    // system("leaks intern");
    return 0;
}