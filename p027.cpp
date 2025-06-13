#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;       // 0 and 1 are not prime
    if (n <= 3) return true;        // 2 and 3 are prime

    if (n % 2 == 0 || n % 3 == 0)   // Eliminate multiples of 2 and 3
        return false;

    // Check for factors from 5 to sqrt(n), skipping even multiples
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int countConsecutivePrimes(int a, int b) {
    int n = 0;
    while (true) {
        int val = n * n + a * n + b;
        if (!isPrime(val))
            break;
        ++n;
    }
    return n;
}

int main() {
    int maxCount = 0;
    int bestA = 0, bestB = 0;

    for (int a = -1000; a <= 1000; ++a) {
        for (int b = -1000; b <= 1000; ++b) {
            int count = countConsecutivePrimes(a, b);
            if (count > maxCount) {
                maxCount = count;
                bestA = a;
                bestB = b;
            }
        }
    }

    cout << "Best polynomial: n^2 + (" << bestA << ")n + (" << bestB << ")\n";
    cout << "Consecutive primes produced: " << maxCount << endl;
    cout << "Product of coefficients (a * b): " << bestA * bestB << endl;

    return 0;
}