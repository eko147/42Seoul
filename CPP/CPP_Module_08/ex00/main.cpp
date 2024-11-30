#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        int valueToFind = 6;

        std::vector<int>::iterator result = easyfind(vec, valueToFind);

        std::cout << "Value : " << *result << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
