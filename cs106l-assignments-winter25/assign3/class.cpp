#pragma once

#include "class.h"
#include <iostream>

template<typename T>
Stack<T>::Stack(std::initializer_list<T> init) {
    size = init.size() + 1;
    top = 0;
    stk = new int[size];
    for (auto ele: init) {
        stk[top] = ele;
        ++top;
    }
}

template<typename T>
Stack<T>::Stack() {
    size = 4;
    top = 0;
    stk = new int[size];
}

template<typename T>
void Stack<T>::resize() {
    size *= 2;
    iterator duplicate = new int[size];
    for (int i = 0; i < top; i++) {
        duplicate[i] = stk[i];
    }
    delete[] stk;
    stk = duplicate;
}

template<typename T>
T Stack<T>::getTop() const {
    return stk[top - 1];
}

template<typename T>
void Stack<T>::push(T ele) {
    if (top >= size) {
        resize();
    }

    stk[top] = ele;
    ++top;
}

template<typename T>
void Stack<T>::pop() {
    top--;
    stk[top] = 0;
}

template<typename T>
void Stack<T>::setTop(T val) {
    if (val < top) {
        for (int i = 0; i < top - val; i++)
            pop();
        top = val;
    }
}