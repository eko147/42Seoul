#ifndef SED_HPP
#define SED_HPP

#include <fstream>
#include <iostream>
#include <string>

class Sed
{
private:
    std::string _filename;
    std::string _str1;
    std::string _str2;
    std::string replaceString();
    std::string fixLine(std::string line);

public:
    std::string openFile();
    void replaceFile(std::string str);
    void saveNew(std::string str);
    Sed(std::string filename, std::string str1, std::string str2);
    ~Sed();
};

void exitFromError(std::string str);

#endif
