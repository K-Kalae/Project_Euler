def find_pythagorean_triplet(sum_target):
    for m in range(1, 1000):
        for n in range(1, m):  # n < m to ensure positive b
            a = 2 * m * n
            b = m**2 - n**2
            c = sum_target - a - b
            if a**2 + b**2 == c**2:
                print(f"a = {a}, b = {b}, c = {c}")
                return a* b* c
    return None

# Call the function with target sum 1000
triplet = find_pythagorean_triplet(1000)
if triplet:
    print("Triplet found:", triplet)
else:
    print("No triplet found.")
