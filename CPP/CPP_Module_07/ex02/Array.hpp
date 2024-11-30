#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> 
class Array
{
private:
    T *_array;
    unsigned int _arraySize;
    
public:
    Array() : _array(NULL), _arraySize(0) {}
    Array(unsigned int n) : _array(new T[n]), _arraySize(n) {}
    Array(const Array& obj) : _array(new T[obj._arraySize]), _arraySize(obj._arraySize){
        for (unsigned int i = 0; i < _arraySize; ++i)
            _array[i] = obj._array[i];
    }
    ~Array(){
        if (_array != NULL)
			delete[] this->_array;
        this->_array = NULL;
        this->_arraySize = 0;
    }

    Array &operator=(const Array &other){
        if (this != &other) {
            delete[] _array;
            _arraySize = other._arraySize;
            _array = new T[_arraySize];
            for (unsigned int i = 0; i < _arraySize; ++i) {
                _array[i] = other._array[i];
            }
        }
        return *this;
    }

    const T &operator[](unsigned int index) const {
        if (index >= _arraySize)
            throw std::out_of_range("Index out of bounds");
        return _array[index];
    }

    T &operator[](unsigned int index){
        if (index >= _arraySize)
            throw std::out_of_range("Index out of bounds");
        return _array[index];
    }

    unsigned int size() const{
        return _arraySize;
    }
};

#endif