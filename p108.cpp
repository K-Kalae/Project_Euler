#include <iostream>
#include <cmath>
using namespace std;

//My understanding of the problem
// Given a diophantine equation 1/x + 1/y = 1/n find the first n for which the distinct solutions to the equation
// are greater than 1000
// Solving the equation by hand computation for different n starting from 2 ... 
// showed that there was a clear relationship between the number
// of divisors of n^2 and the number of (distinct) solutions
// no of distinct solutions = ceil(divisors(n^2) / 2)

// I used help from AI to guide me with a function that counts divisors of a positive square
// and continued from that point

// Function to count the number of positive divisors of n^2
int countDivisorsOfNSquared(int n) {
    int count = 1;
    int num = n;

    // Try all integers from 2 to sqrt(n) as possible prime factors
    for (int p = 2; p * p <= num; ++p) {
        int exponent = 0;
        while (n % p == 0) {
            n /= p;
            ++exponent;
        }
        // Each prime factor contributes (2 * exponent + 1) to divisors of n^2
        if (exponent > 0) {
            count *= (2 * exponent + 1);
        }
    }

    // If n is still greater than 1, it’s a prime factor itself
    if (n > 1) {
        count *= 3; // since exponent = 1 → 2*1 + 1 = 3
    }

    return count;
}

int main() {
    int n = 1;
    while (true) {
        int divisors = countDivisorsOfNSquared(n);
        int numSolutions = (divisors + 1) / 2; // ceil(divisors / 2)

        if (numSolutions > 4000000) {
            cout << "Smallest n with over 1000 solutions: " << n << endl;
            break;
        }
        ++n;
    }

    return 0;
}
