#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#define MAX_INTEGER 2147483647


class RPN
{
private:
    std::stack<int> _stack;
    int performOperation(char op, int operand1, int operand2);

public:
    RPN();
    ~RPN();
    RPN(const RPN &obj);
    RPN &operator=(const RPN &obj);

    int evaluateRPN(const std::string &expression); 
};

#endif
