#include <iostream>

template <typename T>
concept Comparable = requires(const T a, const T b) {
    {a < b} -> std::convertible_to<bool>;
};

template <Comparable T>
T min(const T& v) { return v; }

template <Comparable T, Comparable... Args>
T min(const T& v, const Args&... args) {
    auto m = min(args...);
    return v < m ? v : m;
}

int main() {
    int res = min(1, 3, 4, 5, 2);
    std::cout << res << std::endl;
    return 0;
}