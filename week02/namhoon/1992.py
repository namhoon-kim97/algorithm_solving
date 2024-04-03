from typing import List
import sys

input = sys.stdin.readline


def solve(map: List[str]) -> str:
    n = len(map)

    def traverse(r, c, d):
        if d == 1:
            return map[r][c]
        nd = d // 2
        nw = traverse(r, c, nd)
        ne = traverse(r, c + nd, nd)
        sw = traverse(r + nd, c, nd)
        se = traverse(r + nd, c + nd, nd)
        if len(nw) == 1 and nw == ne == se == se:
            return nw
        return "(" + nw + ne + sw + se + ")"

    return traverse(0, 0, n)


if __name__ == "__main__":
    n = int(input())
    rows = []
    for i in range(n):
        rows.append(input().strip())
    res = solve(rows)
    print(res)
