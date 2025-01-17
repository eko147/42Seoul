#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter (const T *array, const size_t length, void (*func)(const T &)){
	for (size_t i = 0; i < length; i++)
		func(array[i]);
};

template <typename T>
void print(const T& src) {
	std::cout << src << " ";
}

#endif

