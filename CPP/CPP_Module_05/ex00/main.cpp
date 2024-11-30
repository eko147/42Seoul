#include "Bureaucrat.hpp"

int main() 
{
    try 
    {
        Bureaucrat bureaucrat("EJ", 150);
        std::cout << "Created bureaucrat: " << bureaucrat << std::endl;
        
        bureaucrat.incrementGrade();
        std::cout << "After increment: " << bureaucrat << std::endl;

        bureaucrat.decrementGrade();
        std::cout << "After decrement: " << bureaucrat << std::endl;
    } 
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
    } 
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}