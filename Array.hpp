#pragma once
#include <iostream>

template <typename Data>
class Array {
public:
    Data* array;
    int size;       // текущая ёмкость массива
    int capacity; // размерность массива

    Array() : array(nullptr), size(0), capacity(1000) {
        array = new Data[capacity];
    }

    ~Array() {
        delete[] array;
    }

    Data& operator[](int index) {
        if(index >= capacity){
            capacity = index;
            Data* newArray = new Data[capacity];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
        return array[index];
    }

    void push_front(const Data& value){ //добавление в начало массива
        if (size == capacity) {
            int newCapacity = capacity * 2;
            Data* newArray = new Data[newCapacity];

            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }

            delete[] array; 
            array = newArray;
            capacity = newCapacity;
        }
        for (int i = size; i > 0; i--) { 
            array[i] = array[i - 1];
        }

        array[0] = value;
        size++;
    }

    void push_back(const Data& value){
        if (size == capacity) {
            int newCapacity = capacity * 2;
            Data* newArray = new Data[newCapacity];

            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }

            delete[] array;
            array = newArray;
            capacity = newCapacity;
        }

        array[size] = value;
        size++;
    }

    void push_in(int index, const Data& value){
        if (index < 0 || index > size) {
            std::cout << "Invalid index" << std::endl;
            return;
        }

        if (size == capacity) {
            int newCapacity = capacity * 2;
            Data* newArray = new Data[newCapacity];

            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }

            delete[] array;
            array = newArray;
            capacity = newCapacity;
        }

        for (int i = size; i > index; i--) {
            array[i] = array[i - 1];
        }

        array[index] = value;
        size++;
    }

    void pop_front(){
        if (size <= 0) {
            std::cout << "Array is empty, cannot pop front." << std::endl;
        } else {
            for (int i = 0; i < size - 1; i++) {
                array[i] = array[i + 1];
            }
            size--;
        }
    }

    void pop_back(){
        if (size > 0) {
            size--;
        } else {
            std::cout << "Array is empty, cannot pop back." << std::endl;
        }
    }

    void pop_in(int index){
        if (index < 0 || index >= size) {
            std::cout << "Invalid index" << std::endl;
            return;
        }
        for (int i = index; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
    }

    void search(const Data& value){
        for (int i = 0; i < size; i++) {
            if (array[i] == value) {
                std::cout << "Found!" << std::endl;
                return;
            }
        }
        std::cout << "Not found!" << std::endl;
    }

    void search_index(const int index){
        if (index >= 0 && index < size) {
            std::cout << array[index] << std::endl;
        } else {
            std::cout << "Invalid index" << std::endl;
        }
    }

    void display(){
        for (int i = 0; i < size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    void set(const int index, Data value){
        if (index >= 0 && index <= size) {
            array[index] = value;
            std::cout << array[index] << std::endl;
        } else {
            std::cout << "Invalid index" << std::endl; 
        }
    }
};