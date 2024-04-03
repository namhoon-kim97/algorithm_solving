import sys
import heapq

input = sys.stdin.readline


def solution():
    area = 1
    h = []

    for end, dist in st:
        active_circles = False
        last_point = end
        start = end - dist
        while h:
            e, d = heapq.heappop(h)
            e = -e
            if e <= start:
                heapq.heappush(h, (-e, d))
                break
            if e != last_point and e - d >= start:
                continue
            if e - d >= start:
                last_point = e - d
            if last_point == start:
                active_circles = True
        area += 1
        if active_circles:
            area += 1
        heapq.heappush(h, (-end, dist))

    return area


n = int(input())
circles = [list(map(int, input().split())) for _ in range(n)]
st = []
for x, r in circles:
    st.append((x + r, 2 * r))
st.sort()
print(solution())
