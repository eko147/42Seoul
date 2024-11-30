#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj){
	*this = obj;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj){
	(void) obj;
	return (*this);}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::doublePoint(double result)
{
	std::ostringstream oss;
	oss << result;
	std::string str = oss.str();
	size_t i = str.find('.');
	if (i == std::string::npos)
		return false;
	return true;
}

bool ScalarConverter::floatPoint(float result)
{
	std::ostringstream oss;
	oss << result; 
	std::string str = oss.str();
	size_t i = str.find('.');
	if (i == std::string::npos)
		return false;
	return true;
}

void ScalarConverter::convertToChar(const double result)
{
	if (std::isprint(static_cast<char>(result)) == 0)
		std::cout << "char : Non displayable" << std::endl;
	else if (result < std::numeric_limits<char>::min() || result > std::numeric_limits<char>::max())
		std::cout << "char : impossible" << std::endl;
	else
		std::cout << "char : " << static_cast<char>(result) << std::endl;
}

void ScalarConverter::convertToInt(const double result) 
{
	if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
		std::cout << "int : impossible" << std::endl;
    else{
        std::cout << "int : " << static_cast<int>(result) << std::endl;
	}
}

void ScalarConverter::convertToFloat(const double result)
{
	if (result > std::numeric_limits<float>::max())
		std::cout << "float: inff" << std::endl;
	else if (result < -std::numeric_limits<float>::max()) 
		std::cout << "float: -inff" << std::endl;
	else if (floatPoint(result))
		std::cout << "float : " << static_cast<float>(result) << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(result) << ".0f" << std::endl;
}

void ScalarConverter::convertToDouble(const double result)
{
	if (result > std::numeric_limits<double>::max())
		std::cout << "double: inf" << std::endl;
	else if (result < -std::numeric_limits<double>::max())
		std::cout << "double: -inf" << std::endl;
	else if (doublePoint(result))
		std::cout << "double : " << result << std::endl;
	else
		std::cout << "double: " << result << ".0" << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
    char *endptr;
	double result;

	if (literal.length() == 1 && !std::isdigit(literal[0]))
			result = static_cast<double>(literal[0]);
	else
	{
		result = std::strtod(literal.c_str(), &endptr);
		 if (literal[literal.length() - 1] == 'f' && literal != "inf" && literal != "-inf" && literal != "+inf")
			literal.pop_back();
		else if (literal == "nan" || literal == "nanf" || *endptr != '\0' || literal.size() == 0)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return ;
		}
	}
	convertToChar(result);
	convertToInt(result);
	convertToFloat(result);
	convertToDouble(result);
}
