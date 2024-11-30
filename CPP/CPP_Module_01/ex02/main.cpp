#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "문자열 변수의 메모리 주소 : " << &str << std::endl;
    std::cout << "stringPTR이 가리키는 메모리주소 : " << stringPTR << std::endl;
    std::cout << "stringREF가 참조하는 메모리주소 : " << &stringREF << std::endl;

    std::cout << "문자열 변수의 값 : " << str << std::endl;
    std::cout << "stringPTR이 가리키는 값 : " << *stringPTR << std::endl;
    std::cout << "stringREF가 참조하는 값 : " << stringREF << std::endl;
}
