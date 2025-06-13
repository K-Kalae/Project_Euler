import itertools
cache = {0: 0, 1: 1}

def fibonacci_of(n):
    if n in cache:  # Base case
       return cache[n]
   # Compute and cache the Fibonacci number
    cache[n] = fibonacci_of(n - 1) + fibonacci_of(n - 2)  # Recursive case
    return cache[n]

def main():
    total = 0
    for i in itertools.count():
        fib = fibonacci_of(i)
        if fib > 4000000:
            break
        if fib % 2 == 0:
            total += fib

    print(total)


    
if __name__ == '__main__':
    main()