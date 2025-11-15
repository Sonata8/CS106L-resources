#include <iostream>
#include "IntVector.cpp"

int main() {
    IntVector v;
    v.push_back(114);
    v.push_back(514);
    v.push_back(1919);
    v.push_back(810);
    v.push_back(233);
    v.push_back(666);
    std::cout << "Length now: " << v.size() << "\n";
    v.push_back(8964);
    std::cout << *v.begin() << "\n";
    std::cout << v[3] << " " << v.at(3) << "\n";
    v.at(3) = 811;
    std::cout << v[3] << "\n";

    for (auto x: v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}