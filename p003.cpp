#include <iostream>
#include <cmath>
using namespace std;

long long largestPrimeFactor(long long n) {
    long long maxPrime = -1;

    
    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }

    
    for (long long i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n /= i;
        }
    }

    
    if (n > 2)
        maxPrime = n;

    return maxPrime;
}

int main() {
    long long num;
    cout << "Enter a number: ";
    cin >> num;

    if (num <= 1)
        cout << "No prime factors for " << num << endl;
    else
        cout << "Largest prime factor of " << num << " is: " << largestPrimeFactor(num) << endl;

    return 0;
}
