import math

def count_singular_pythagorean_perimeters(limit=1_500_000):
    """
    Returns the number of perimeters p ≤ limit that can be written in
    exactly one way as the sum of the sides of an integer right-triangle.
    """
    # index = perimeter, value = number of distinct (a,b,c) giving that perimeter
    per_counts = [0] * (limit + 1)

    # Euclid’s formula: generate primitive triples
    m_max = int((limit / 2) ** 0.5) + 1          # upper bound for m
    for m in range(2, m_max):
        for n in range(1, m):
            if (m - n) & 1 and math.gcd(m, n) == 1:      # opposite parity, coprime
                a = m * m - n * n
                b = 2 * m * n
                c = m * m + n * n
                p0 = a + b + c                           # primitive perimeter
                if p0 > limit:
                    continue

                # add all multiples k·p0 (non-primitive triples)
                for k in range(1, limit // p0 + 1):
                    per_counts[k * p0] += 1

    # count perimeters that occur exactly once
    return sum(1 for cnt in per_counts if cnt == 1)

if __name__ == "__main__":
    result = count_singular_pythagorean_perimeters(1_500_000)
    print(result)        
