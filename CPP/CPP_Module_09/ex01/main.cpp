#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " \"RPN expression\"" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    
    RPN RPN;
    std::string expression = argv[1];
    int result = RPN.evaluateRPN(expression);
    std::cout << result << std::endl;

    return 0;
}