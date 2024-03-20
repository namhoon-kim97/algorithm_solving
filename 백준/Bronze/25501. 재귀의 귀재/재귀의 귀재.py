import sys

input = sys.stdin.readline


def recursion(s, l, r):
    global cnt
    if l >= r:
        return 1
    elif s[l] != s[r]:
        return 0
    else:
        cnt += 1
        return recursion(s, l + 1, r - 1)


def isPalindrome(s):
    return recursion(s, 0, len(s) - 1)


t = int(input())
a = [input().rstrip() for _ in range(t)]
for s in a:
    cnt = 1
    print(isPalindrome(s), cnt)
