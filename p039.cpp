#include <iostream>
#include <set>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int countDistinctTripletsWithPerimeter(int targetPerimeter) {
    set<tuple<int, int, int>> triplets;

    for (int m = 2; ; ++m) {
        for (int n = 1; n < m; ++n) {
            int a = m * m - n * n;
            int b = 2 * m * n;
            int c = m * m + n * n;
            int sum = a + b + c;

            if (sum > targetPerimeter)
                break;

            if (targetPerimeter % sum == 0) {
                int k = targetPerimeter / sum;
                int ka = k * a;
                int kb = k * b;
                int kc = k * c;

                vector<int> sides = {ka, kb, kc};
                sort(sides.begin(), sides.end());

                triplets.emplace(sides[0], sides[1], sides[2]);
            }
        }

        if (2 * m * m > targetPerimeter)
            break;
    }

    // Optional: print all solutions
    cout << "Distinct Pythagorean triplets with perimeter " << targetPerimeter << ":\n";
    for (auto& [a, b, c] : triplets) {
        cout << "(" << a << ", " << b << ", " << c << ")\n";
    }

    cout << "Total number of distinct triplet solutions: " << triplets.size() << endl;
    return triplets.size();
}

int main() {
    int perimeter;
    int maxCount = 0;
int maxPerimeter = 0;

for (int perimeter = 0; perimeter <= 1000; perimeter++)
{
    int count = countDistinctTripletsWithPerimeter(perimeter);
    if (count > maxCount)
    {
        maxCount = count;
        maxPerimeter = perimeter;
    }
}

cout << "Perimeter with the most distinct Pythagorean triplets: " 
     << maxPerimeter << " (" << maxCount << " triplets)" << endl;
    return 0;
}
