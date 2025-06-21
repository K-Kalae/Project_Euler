#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull mod_pow(ull base, ull exp, ull mod) {
    ull result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)  // if exp is odd
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int main() {
    ull mod = 10000000000ULL; // 10^10
    ull power = mod_pow(2, 7830457, mod);
    ull result = (28433 * power + 1) % mod;

    cout << "Last 10 digits: " << result << endl;
    return 0;
}
