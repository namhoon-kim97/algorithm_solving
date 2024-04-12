import sys

input = sys.stdin.readline


def F(x):
    x_str = str(x)
    first_digit = int(x_str[0])
    num_digits = len(x_str)
    return first_digit * num_digits


def is_FA_number(x):
    history = set()
    while True:
        x = F(x)
        if x in history:
            return "FA"
        history.add(x)


num = int(input())

if is_FA_number(num):
    print("FA")
else:
    print("NFA")
