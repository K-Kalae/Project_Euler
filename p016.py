def sum_of_digits_of_power_of_two(exponent):
    # Step 1: Compute 2^exponent
    number = 2 ** exponent

    # Step 2: Convert number to string and sum its digits
    digit_sum = sum(int(digit) for digit in str(number))

    return digit_sum

# Example usage
print(sum_of_digits_of_power_of_two(1000))
