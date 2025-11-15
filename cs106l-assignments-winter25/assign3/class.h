#pragma once

#include <initializer_list>

template<typename T>
class Stack {
    using iterator = T*;
private:
    int top, size;
    iterator stk;
    void resize();

public:
    Stack(std::initializer_list<T> init);
    Stack();
    T getTop() const;
    void push(T ele);
    void pop();
    void setTop(T val);
};

#include "class.cpp"