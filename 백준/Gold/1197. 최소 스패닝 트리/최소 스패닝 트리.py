import sys

input = sys.stdin.readline


def find(x):
    if p[x] == x:
        return x
    return find(p[x])


def is_diff_group(a, b):
    a = find(a)
    b = find(b)
    if a == b:
        return False
    if p[a] == p[b]:
        p[a] += 1
    if p[a] < p[b]:  # b그룹이 더 높은 루트
        p[b] = a
    else:  # a그룹이 더 높은 경우
        p[a] = b
    return True


v, m = map(int, input().split())
adj = []
p = [i for i in range(v + 1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    adj.append((c, a, b))
adj.sort()

cnt = 0
ans = 0
for i in range(m):
    cost, a, b = adj[i]
    if not is_diff_group(a, b):
        continue
    cnt += 1
    ans += cost
    if cnt == v - 1:
        break

print(ans)
