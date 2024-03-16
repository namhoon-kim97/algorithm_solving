import sys

input = sys.stdin.readline

def solution(row, col, diag1, diag2):
    if row == n:
        global cnt
        cnt += 1
        return
    avilable_positions = ((1 << n) - 1) & ~(col | diag1 | diag2)
    while avilable_positions:
        position = avilable_positions & -avilable_positions
        avilable_positions -= position
        solution(
            row + 1, col | position, (diag1 | position) << 1, (diag2 | position) >> 1
        )


cnt = 0
n = int(input())

solution(0, 0, 0, 0)
print(cnt)
