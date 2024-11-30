#include "RPN.hpp"

RPN::~RPN(){}
RPN::RPN(){}
RPN::RPN(const RPN &obj){
	*this = obj;
}

RPN &RPN::operator=(const RPN &obj){
	(void)obj;
	return *this;
}

int RPN::evaluateRPN(const std::string &expression) { 
    std::istringstream iss(expression);

    std::string token; 

    while (iss >> token) {
        if (isdigit(token[0]) && token.size() == 1) {
            _stack.push(std::atoi(token.c_str()));
            if(_stack.top() > 9 ) 
            {
                std::cout << "Error" << std::endl;
                std::exit(EXIT_FAILURE);
            }
        }
        else if (token.size() == 1 && strchr("+-*/", token[0])) {
            if (_stack.size() < 2) { 
                std::cout << "Error: Insufficient operands for operator." << std::endl;
                std::exit(EXIT_FAILURE);
            }
            int operand2 = _stack.top();
            _stack.pop();
            int operand1 = _stack.top();
            _stack.pop();
            int result = performOperation(token[0], operand1, operand2);
            _stack.push(result);
        }
        else {
            std::cout << "Error: Invalid token" << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
    if (_stack.size() != 1) { 
        std::cout << "Error: Malformed expression" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return _stack.top();
}

int RPN::performOperation(char op, int operand1, int operand2) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                std::cout << "Error: Division by zero" << std::endl;
                std::exit(EXIT_FAILURE);
            }
            return operand1 / operand2;
        default:
            std::cout << "Error: Invalid operator" << std::endl;
            std::exit(EXIT_FAILURE);
    }
}