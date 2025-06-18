from math import isqrt
from functools import lru_cache

# Efficient primality check
@lru_cache(maxsize=None)
def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, isqrt(n) + 1, 2):
        if n % i == 0:
            return False
    return True

# Check if both concatenations of two primes are prime
@lru_cache(maxsize=None)
def is_concat_prime(p1, p2):
    return is_prime(int(str(p1) + str(p2))) and is_prime(int(str(p2) + str(p1)))

# Generate primes up to a limit
def generate_primes(limit):
    sieve = [True] * limit
    sieve[0:2] = [False, False]
    for i in range(2, isqrt(limit) + 1):
        if sieve[i]:
            for j in range(i*i, limit, i):
                sieve[j] = False
    return [x for x, is_p in enumerate(sieve) if is_p]

# Try to build a group recursively
def find_prime_group(primes, group_size):
    def search(path, start_index):
        if len(path) == group_size:
            return path
        for i in range(start_index, len(primes)):
            p = primes[i]
            if all(is_concat_prime(p, q) for q in path):
                result = search(path + [p], i + 1)
                if result:
                    return result
        return None

    for i in range(len(primes)):
        group = search([primes[i]], i + 1)
        if group:
            return group
    return None

# Main execution
def main():
    primes = generate_primes(10000)
    result = find_prime_group(primes, 5)
    if result:
        print("Prime set:", result)
        print("Sum:", sum(result))
    else:
        print("No valid set found.")

if __name__ == "__main__":
    main()
