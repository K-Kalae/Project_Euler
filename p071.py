from math import gcd

max_numerator = 0
max_denominator = 1

for b in range(2, 1_000_001):
    a = (3 * b - 1) // 7  # ensures a/b < 3/7
    if gcd(a, b) == 1:
        if a * max_denominator > max_numerator * b:
            max_numerator, max_denominator = a, b

print(max_numerator)

# from math import gcd

# max_numerator = 0
# max_denominator = 1

# for b in range(2, 1_000_001):
#     a = (3 * b - 1) // 7  # ensures a/b < 3/7
#     if gcd(a, b) == 1:
#         if a * max_denominator > max_numerator * b:
#             max_numerator, max_denominator = a, b
#             print(f"{max_numerator}/{max_denominator}")
