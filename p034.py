import math



def sum_digits(n):
    return sum(math.factorial(int(digit)) for digit in str(n))