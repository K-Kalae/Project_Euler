#include <iostream>
#include <vector>
using namespace std;

//The question requires the lcms of 1,2,...20 which can be computed by iteratively computing the lcm of a current result with
// a the next number in the list

// GCD using Euclidean algorithm
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// LCM using GCD
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    vector<long long> numbers(20);
    cout << "Enter 20 positive integers:\n";
    for (int i = 0; i < 20; ++i) {
        cin >> numbers[i];
        if (numbers[i] <= 0) {
            cout << "Invalid input. All numbers must be positive." << endl;
            return 1;
        }
    }

    long long result = numbers[0];
    for (int i = 1; i < 20; ++i) {
        result = lcm(result, numbers[i]);
    }

    cout << "LCM of the 20 numbers is: " << result << endl;
    return 0;
}
