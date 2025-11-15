这个作业的任务是自己设计一个类。可以发挥脑洞，只需要满足以下几个点：

1. 要有一个无参数的默认 constructor 和一个有参数的 constructor ；
2. private 域里至少要有一个成员变量、至少要有一个成员函数；
3. **public 域里至少要有一个关于 private 域的 getter 函数以及 setter 函数。**

第三点是这个作业唯一的坑。要认真阅读 README 文件，在那里面规定了这样的函数的格式：必须是`getData/get_data, setData/set_data`这样子的。其中`data`必须是 private 域里变量的名称，不饿能有额外的东西，否则 auto grader 会判错！

我自己写了一个模拟的栈。但是感觉写的不是很优雅。回头再优化吧（）🤓

以及如果卡在了 ⏳ Installing CastXML... 这个地方，说明你的网络需要用一些魔法（）

```cpp
// class.h
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


// class.cpp
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
```

