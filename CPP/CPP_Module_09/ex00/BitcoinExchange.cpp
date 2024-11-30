#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj){
	*this = obj;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj){
	(void)obj;
	return *this;
}

void BitcoinExchange::getDatabase()
{
    std::ifstream csv("data.csv");
    if (csv.is_open()) {
        std::string line;
        if (!std::getline(csv, line)) {
            csv.close();
            std::cout << "Error: Csv file is empty." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        if (line != "date,exchange_rate") {
            csv.close();
            std::cout << "Error: Invalid csv file." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        while (std::getline(csv, line)) {
            setDataFile(line);
        }
        csv.close();
    }
    else {
        std::cout << "Error: Invalid csv file." << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void BitcoinExchange::setDataFile(std::string line)
{
    std::istringstream ss(line);
    std::string dateStr, valueStr;

    if (std::getline(ss, dateStr, ',') && std::getline(ss, valueStr, ',')){ 
        if(checkDate(dateStr) && isValidValue(valueStr) != NEGATIVE) 
            _database[dateStr] = std::stod(valueStr); //
            
        else{
            std::cout << "Error: Invalid data in line" << std::endl;
            std::exit(EXIT_FAILURE);
        }
        
    }
    else{
        std::cout << "Error: Invalid csv file." << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

ValidationResult BitcoinExchange::isValidValue(std::string value)
{
    std::istringstream ss(value);
    double bitcoinValue;
    ss >> bitcoinValue;
    if (ss.fail() == true || !ss.eof())
        return INVALID_FORMAT;
    if (bitcoinValue < 0) 
        return NEGATIVE;
    if (bitcoinValue > 1000) 
        return OUT_OF_RANGE;
    return VALID;
}

int  BitcoinExchange::convertToInt(const std::string& str) {
    std::istringstream iss(str);
    int result;

    iss >> result;

    if (iss.fail()) {
        std::cout << "Invalid argument" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    if (result < 0 ) {
        std::cout << "Invalid argument" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return result;
}

bool BitcoinExchange::checkDate(std::string date)
{
    int year, month, day;
    std::string str_year, str_month, str_day;

    std::stringstream ss(date);
    if (std::getline(ss, str_year, '-'))
        year = convertToInt(str_year);
    if (std::getline(ss, str_month, '-')){
        month = convertToInt(str_month);
        if (month < 1 || month > 12)
            return false;
    }
    if (std::getline(ss, str_day, '-')){
        day = convertToInt(str_day);
        if (month == 4 || month == 6 || month == 9 || month == 11){
            if (day < 1 || day > 30)
                return false;
        }
        else if (month == 2){
            int i_year = year;
            if (i_year % 4 == 0 && (i_year % 100 != 0 || i_year % 400 == 0)){
                if (day < 1 || day > 29)
                    return false;
            }
            else{
                if (day < 1 || day > 28)
                    return false;
            }
        }
        else{
            if (day < 1 || day > 31)
                return false;
        }
    }
    if (ss.fail() || !ss.eof())
        return false;
    return true;
}

double BitcoinExchange::convertToDouble(const std::string &str) {
    std::istringstream iss(str);
    double result;

    iss >> result;

    if (iss.fail() || !iss.eof()) {
        std::cout << "Invalid argument" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    if (result < 0) {
        std::cout << "Invalid argument" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return result;
}

void BitcoinExchange::calculateAndPrint(const std::string &date, const std::string &value) {
    double bitcoinValue = convertToDouble(value);
    std::map<std::string, double>::iterator it = _database.lower_bound(date);

    if (it != _database.begin() && it->first != date) 
        --it;
    if (it == _database.begin() && it->first.compare(date) != 0)
    {
        std::cout << "Error: bad Input => " << date << std::endl;
        return ;
    }
    double exchangeRate = it->second;
    double result = bitcoinValue * exchangeRate;
    std::cout << date << " => " << value << " = " << result << std::endl;
}

std::string BitcoinExchange::trimWhitespace(const std::string& str) {
    std::string result = str;

    size_t left = 0;
    while (left < result.length() && std::isspace(result[left])) {
        ++left;
    }
    result.erase(0, left);

    size_t right = result.length();
    while (right > 0 && std::isspace(result[right - 1])) {
        --right;
    }
    result.erase(right);

    return result;
}

void BitcoinExchange::parseLine(const std::string &line, std::string &date, std::string &value) {
    std::istringstream ss(line);
    ValidationResult result;
    if(std::getline(ss, date, '|') && std::getline(ss, value)){
        result = isValidValue(value);
        date = trimWhitespace(date);
        value = trimWhitespace(value);
        if(!checkDate(date))
            std::cout << "Error: Bad input => " << date << std::endl; 
        else if(result == NEGATIVE)
            std::cout << "Error: Not a positive number." << std::endl;
        else if(result == OUT_OF_RANGE)            
            std::cout << "Error: Too large a number." << std::endl;
        else
            calculateAndPrint(date, value);
    }
    else
    {
        if(!ss.eof())
        {
            std::cout << "Error: Input file is empty." << date << std::endl; 
            std::exit(EXIT_FAILURE);
        }
        std::cout << "Error: Bad input => " << line << std::endl;
    }
}

void BitcoinExchange::readFile(const char *fileName)
{
    std::ifstream input(fileName);
    std::string date;
    std::string value;
    if (input.is_open()) {
        std::string line;
        if (!std::getline(input, line)) {
            input.close();
            std::cout << "Error: Input file is empty." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        if (line != "date | value") {
            input.close();
            std::cout << "Error: Invalid input file." << std::endl;
            std::exit(EXIT_FAILURE);
        }
        while (std::getline(input, line)) 
            parseLine(line, date, value);
        input.close();
    }
    else {
        std::cout << "Error: Invalid input file." << std::endl;
        std::exit(EXIT_FAILURE);
    }
}
