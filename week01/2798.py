import sys
from itertools import *

input = sys.stdin.readline

n, m = map(int, input().split())
cards = list(map(int, input().split()))
ans = list(combinations(cards, 3))
ans.sort(key=lambda x: sum(x))

for i in range(len(ans) - 1, -1, -1):
    if sum(ans[i]) > m:
        continue
    else:
        print(sum(ans[i]))
        break
# print(max(x for x in map(sum, combinations(cards, 3)) if x <= m))
