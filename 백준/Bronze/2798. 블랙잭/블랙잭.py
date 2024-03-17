import sys
from itertools import *

input = sys.stdin.readline

n, m = map(int, input().split())
cards = list(map(int, input().split()))

print(max(x for x in map(sum, combinations(cards, 3)) if x <= m))
