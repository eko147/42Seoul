#include "Array.hpp"

#define MAX_VAL 10 

int main(void) {
    Array<int> numbers(MAX_VAL);
    std::srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        int value = std::rand() % 100;
        numbers[i] = value;
    }

    std::cout << "numbers : ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "복사 생성자 테스트" << std::endl;
    try {
        Array<int> tmp(numbers);
        std::cout << "tmp : ";
        for (unsigned int i = 0; i < tmp.size(); i++) {
            std::cout << tmp[i] << " ";
        }
        std::cout << std::endl;
    } catch (std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << std::endl << std::endl;

    std::cout << "복사 잘됐는지 확인" << std::endl;
    try {
        Array<int> tmp0(MAX_VAL);
        tmp0 = numbers;
        std::cout << "tmp0 : ";
        for (unsigned int i = 0; i < tmp0.size(); i++) {
            std::cout << tmp0[i] << " ";
        }
        std::cout << std::endl;
    } catch (std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "길이가 달라도 잘 복사 되는지 확인" << std::endl;
    try {
        Array<int> tmp1(MAX_VAL / 2);
        tmp1 = numbers;
        std::cout << "tmp1 : ";
        for (unsigned int i = 0; i < tmp1.size(); i++) {
            std::cout << tmp1[i] << " ";
        }
        std::cout << std::endl;
    } catch (std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "복사한 배열이 바뀌어도 서로 영향을 주는지 확인" << std::endl;
    try {
        Array<int> tmp2(MAX_VAL);
        tmp2 = numbers;
        std::cout << "tmp2 : ";
        for (unsigned int i = 0; i < tmp2.size(); i++) {
            std::cout << tmp2[i] << " ";
        }
        std::cout << " => ";
        tmp2[3] = -55;
        for (unsigned int i = 0; i < tmp2.size(); i++) {
            std::cout << tmp2[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "numbers : ";
        for (unsigned int i = 0; i < numbers.size(); i++) {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;
    } catch (std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "예외 테스트" << std::endl;
    try {
        numbers[-2] = 0;
    } catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
    try {
        numbers[100] = 0;
    } catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
}