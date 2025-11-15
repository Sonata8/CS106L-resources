#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main() {
    std::list<int> v = {1, 1, 4, 5, 1, 4};
    std::list<int> uni_v, re_u_v;

    std::unique_copy(v.begin(), v.end(), std::back_inserter(uni_v));
    std::unique_copy(v.begin(), v.end(), std::front_inserter(re_u_v));

    for(const auto& val: uni_v) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    for(const auto& val: re_u_v) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}