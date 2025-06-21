#include <iostream>
#include <set>       // For storing unique values
#include <cmath>     // For pow()

int main() {
    std::set<double> memo; // Use set to avoid duplicates

    for (int m = 2; m < 101; ++m) {
        for (int n = 2; n < 101; ++n) {
            double a = pow(m, n);
            memo.insert(a); // insert does nothing if a already exists
        }
    }

    std::cout << "Number of distinct terms: " << memo.size() << std::endl;

    return 0;
}
