#include <iostream>
#include <algorithm>

int main() {
    std::string corlys = "Lord of the tides";

    auto pred = [](auto c) {
            c = std::toupper(c);
            return c == 'A' || c == 'E' || c == 'I' || c == 'U';
        };

    auto it = std::find_if(corlys.begin(), corlys.end(), pred);

    if (it != corlys.end()) {
        std::cout << "Found!" << std::endl;
    } else {
        std::cout << "Ah-oh, Not Found!!" << std::endl;
    }
    
    return 0;
}