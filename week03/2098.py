import sys

# 입력 받기
input = sys.stdin.readline
n = int(input())
w = [list(map(int, input().split())) for _ in range(n)]

# 메모이제이션을 위한 테이블 초기화. 모든 값은 -1로 설정
memo = [[-1] * (1 << n) for _ in range(n)]


def solution(cur, visited):
    # 모든 도시 방문 완료하고 출발지로 돌아올 수 있는 경우
    if visited == (1 << n) - 1:
        return w[cur][0] if w[cur][0] > 0 else sys.maxsize

    # 이미 계산된 상태라면 재사용
    if memo[cur][visited] != -1:
        return memo[cur][visited]

    # 최소 비용 초기화
    min_cost = sys.maxsize
    for i in range(n):
        # i번 도시를 아직 방문하지 않았고, 현재 도시에서 i번 도시로 갈 수 있는 경우
        if not visited & (1 << i) and w[cur][i] > 0:
            # i번 도시를 방문한 상태로 변경
            new_visited = visited | (1 << i)
            print(new_visited)
            # 재귀적으로 다음 도시 방문 처리
            cost = solution(i, new_visited) + w[cur][i]
            min_cost = min(min_cost, cost)

    # 계산된 최소 비용 저장 및 반환
    memo[cur][visited] = min_cost
    return min_cost


# 0번 도시에서 시작, 방문한 도시 상태는 0번 도시만 방문한 상태로 초기화
min_cost = solution(0, 1 << 0)
print(*memo, sep="\n")
print(min_cost)
