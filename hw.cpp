#include <bits/stdc++.h>

using namespace std;

int numberDigit(int n) {
    if (n == 0)
        return 1;
    int count = 0;
    while (n > 0) {
        ++count;
        n /= 10;
    }
    return count;
}

int changeNumber(int x) {
    int last = x % 10;
    int m = x / 10;
    int digitCount = numberDigit(m);
    return last * pow(10, digitCount) + m;
}

int main() {
    int x = 18;
    while (x) {
        int z;
        z = changeNumber(x);
        if (z == (x << 2)) {
            cout << x << endl;
            return 0;
        }
        x += 10;
    }
    return 0;
}