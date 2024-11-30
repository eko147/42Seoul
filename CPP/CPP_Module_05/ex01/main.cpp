#include "Bureaucrat.hpp"

int main() {

    try {
        Bureaucrat bureaucrat("EJ", 31);
        std::cout << "Created bureaucrat: " << bureaucrat << std::endl;

        Form form("Application Form", 40, 30);
        std::cout << "Created form: " << form << std::endl;

        bureaucrat.signForm(form);
    } 
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;} 
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;} 
    catch (const Form::GradeTooLowException& e) {
        std::cerr << "Caught Form::GradeTooLowException: " << e.what() << std::endl;} 
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;}
    return 0;
}