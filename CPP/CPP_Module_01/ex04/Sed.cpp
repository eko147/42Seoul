#include "Sed.hpp"

Sed::Sed(std::string filename, std::string str1, std::string str2)
{
    _filename = filename;
    _str1 = str1;
    _str2 = str2;
}

Sed::~Sed() {}

std::string Sed::openFile()
{
    if (_filename.length() == 0 || _str1.length() == 0)
        exitFromError("Invalid Argument Type");
    return (replaceString());
}

std::string Sed::replaceString()
{
    std::ifstream inFile(_filename);
    if (!inFile)
        exitFromError("Error opening file");
    std::string line;
    std::string newstr;
    while (std::getline(inFile, line))
        newstr += fixLine(line) + '\n';
    inFile.close();
    return (newstr);
}

std::string Sed::fixLine(std::string line)
{
    size_t found = line.find(_str1);
    while (found != std::string::npos)
    {
        line.replace(found, _str1.length(), _str2);
        found = line.find(_str1, found + _str2.length());
    }
    return (line);
}

void Sed::replaceFile(std::string str)
{
    std::ofstream outputFile(_filename + ".replace");
    if (!outputFile)
        exitFromError("Error opening file");
    outputFile << str;
    outputFile.close();
}
