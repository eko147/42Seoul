#ifndef SCALARCONVETER_HPP
#define SCALARCONVETER_HPP

#include <iostream>
#include <sstream>

class ScalarConverter
{
private:
    static void convertToChar(const double result);
    static void convertToInt(const double result);
    static void convertToFloat(const double result);
    static void convertToDouble(const double result);
    static bool doublePoint(double result);
    static bool floatPoint(float result);


    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &obj);
    ~ScalarConverter();

public:
    static void convert(std::string literal); 
};

#endif