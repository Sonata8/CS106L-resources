#include <iostream>
#include <vector>

/*
Actually useless
We don't really need what we want to find to be comparable.
^_^
*/

template <typename T>
concept Comparable = requires(const T a, const T b) {
    {a < b} -> std::convertible_to<bool>;
};

template <typename TIterator, Comparable TValue>
TIterator find(TIterator begin, TIterator end, TValue value) {
    for (auto it = begin; it != end; ++it) {
        if (*it == value) {
            return it;
        }
    }
    return end;
}

int main() {
    std::vector<std::string> v {"seven", "kingdoms"};
    auto it = find<std::vector<std::string>::iterator, std::string>(v.begin(), v.end(), "kingdoms");
    std::cout << *it << std::endl;
    return 0;
}