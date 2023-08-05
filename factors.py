#!/usr/bin/python3

import sys

def factorize(n):
    factors = []
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            factors.append(divisor)
            n //= divisor
        divisor += 1

    return factors

def main():
    if len(sys.argv) != 2:
        print("Usage: {} <file>".format(sys.argv[0]))
        sys.exit(1)

    input_file = sys.argv[1]

    try:
        with open(input_file, 'r') as file:
            for line in file:
                n = int(line.strip())
                factors = factorize(n)
                factors_str = '*'.join(map(str, factors))
                print("{}={}".format(n, factors_str))

    except FileNotFoundError:
        print("Error: File '{}' not found.".format(input_file))
        sys.exit(1)

if __name__ == "__main__":
    main()

