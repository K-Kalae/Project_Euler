#include <iostream>
#include <vector>
#include <cmath>

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int sqrt_n = std::sqrt(n);
    for (int i = 3; i <= sqrt_n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    std::vector<int> primes;
    int num = 2;

    while (num < 2000000) {
        if (is_prime(num)) {
            primes.push_back(num);
            }
        num++;
    }

    long long sum = 0;

    for (int num : primes) {
        sum += num;
    }

    std::cout << "Sum = " << sum << std::endl;
    return 0;
}
