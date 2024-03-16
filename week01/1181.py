import sys

input = sys.stdin.readline

n = int(input())
a = list(set([input().rstrip() for _ in range(n)]))
a.sort()
a.sort(key=lambda x: len(x))
print(*(a), sep="\n")
