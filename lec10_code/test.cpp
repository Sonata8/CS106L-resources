#include <iostream>
#include <vector>

template <typename TIterator, typename Pred>
TIterator find(TIterator begin, TIterator end, Pred pred) {
    for (auto it = begin; it != end; ++it) {
        if (pred(*it)) {
            return it;
        }
    }
    return end;
}

int main() {
    std::vector<int> vec{114, 51, 4};
    int n;
    std::cin >> n;
    auto isLessThanN = [n](int x) { return x < n; };
    std::cout << *find(vec.begin(), vec.end(), isLessThanN) << std::endl;
    return 0;
}