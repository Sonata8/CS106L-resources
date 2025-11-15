#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string init = "WWH CN SYSU Computer Science";

    std::stringstream ss;
    ss << init;

    std::string name;
    std::string nation;
    std::string univ;
    std::string interest;

    ss >> name >> nation >> univ;
    std::getline(ss, interest);

    std::cout << name + ", " << nation + ", " << univ + ", " << interest + "\n";


    return 0;
}