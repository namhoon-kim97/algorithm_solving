def change_to_n(num, n):
    ret = []
    while num >= n:
        ret.append(num % n)
        num //= n
    ret.append(num)
    return ret[::-1]


def sum_of_nums(num):
    ret = 0
    for i in num:
        ret += i
    return ret


def solution(num):
    sum_10 = sum_of_nums(change_to_n(num, 10))
    sum_12 = sum_of_nums(change_to_n(num, 12))
    sum_16 = sum_of_nums(change_to_n(num, 16))
    if sum_10 == sum_12 and sum_12 == sum_16:
        return True
    else:
        return False


for i in range(1000, 10000):
    if solution(i):
        print(i)
