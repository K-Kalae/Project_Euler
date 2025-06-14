def is_palindrome(s):
    s = str(s).lower().replace(" ", "")  # Optional: normalize input
    return s == s[::-1]


def main():
    max = 0
    for a in range (100, 999):
        for b in range(100, 999):
            if is_palindrome(a*b):
                if (a*b)> max:
                    max = (a*b)
                print(a*b)
    print(max)

main()
