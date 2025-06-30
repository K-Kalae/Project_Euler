import time
import itertools

start_time = time.time()

def is_prime(n):
    """Check if a number is prime."""
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True



def find_largest_pandigital_prime(n):
    digits = ''.join(str(i) for i in range(n, 0, -1))  
    for p in itertools.permutations(digits):
        num = int(''.join(p))
        if is_prime(num):
            return num
    return None

for n in range(9, 0, -1):
    result = find_largest_pandigital_prime(n)
    if result:
        print(f"Largest {n}-digit pandigital prime: {result}")
        break

end_time = time.time()
elapsed_time = end_time - start_time

print(f"Execution time: {elapsed_time:.4f} seconds")
