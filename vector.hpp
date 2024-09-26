#pragma once

#include <stdexcept>

template <typename T>
class Vector {
private:
    T* data;
    int size;
    int capacity;

public:
    Vector(int initialCapacity = 10) {
        data = new T[initialCapacity];
        size = 0;
        capacity = initialCapacity;
    }

    ~Vector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            // увеличиваем размер массива
            int newCapacity = capacity * 2;
            T* newData = new T[newCapacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size] = value;
        size++;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};