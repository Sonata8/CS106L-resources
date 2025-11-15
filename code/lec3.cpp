#include <iostream>

int main() {
    int numOne = 12.0;
    int numTwo(12.0);
    int numThree{12.0};

    std::cout << numOne << std::endl;
    std::cout << numTwo << std::endl;

    return 0;
}