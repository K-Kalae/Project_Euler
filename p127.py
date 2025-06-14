from math import gcd
from functools import reduce
from array import array

LIMIT = 120000

# Step 1: Compute rad(n) for all n using sieve
rad = array('L', [1] * (LIMIT + 1))
for i in range(2, LIMIT + 1):
    if rad[i] == 1:  # i is prime
        for j in range(i, LIMIT + 1, i):
            rad[j] *= i

# Step 2: Main loop to find abc-hits
total = 0

for c in range(1, LIMIT):
    for a in range(1, c // 2 + 1):  # a < b implies a < c/2
        b = c - a

        if gcd(a, b) != 1:
            continue
        if gcd(a, c) != 1 or gcd(b, c) != 1:
            continue

        rad_abc = rad[a] * rad[b] * rad[c]
        if rad_abc < c:
            total += c
            # Uncomment to log hits:
            print(f"abc-hit: a={a}, b={b}, c={c}, rad(abc)={rad_abc}")

print("Correct sum of abc-hits c:", total)
