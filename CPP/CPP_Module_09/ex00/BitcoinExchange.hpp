#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>


enum ValidationResult {
    VALID,
    INVALID_FORMAT,
    OUT_OF_RANGE,
    NEGATIVE,
    POSITIVE,
};

class  BitcoinExchange
{
public:
    void getDatabase();
    void readFile(const char *fileName);

    BitcoinExchange();
    ~ BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &obj);
    BitcoinExchange &operator=(const BitcoinExchange &obj);

private:
    std::map<std::string, double> _database;
    std::string trimWhitespace(const std::string& str);
    void setDataFile(std::string line);
    bool checkDate(std::string date);
    int convertToInt(const std::string& str);
    void parseLine(const std::string &line, std::string &date, std::string &value);
    double convertToDouble(const std::string &str);
    void calculateAndPrint(const std::string &date, const std::string &value);
    ValidationResult isValidValue(std::string value);
};

#endif