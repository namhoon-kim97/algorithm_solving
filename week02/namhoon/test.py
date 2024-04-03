import sys
from collections import deque

input = sys.stdin.readline


def bfs(start_x, start_y, is_RB, letter):

    queue = deque([])
    queue.append([start_x, start_y])
    if is_RB:
        RBG_graph[start_x][start_y] = 0
    else:
        graph[start_x][start_y] = 0

    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = dx[i] + x
            ny = dy[i] + y
            if is_RB:
                if letter == "R" or letter == "G":
                    if 0 <= nx < case and 0 <= ny < case:
                        if RBG_graph[nx][ny] == "R" or RBG_graph[nx][ny] == "G":
                            queue.append([nx, ny])

                            RBG_graph[nx][ny] = 0
                elif 0 <= nx < case and 0 <= ny < case and letter == "B":
                    queue.append([nx, ny])
                    RBG_graph[nx][ny] = 0
            else:
                if 0 <= nx < case and 0 <= ny < case and letter == graph[nx][ny]:
                    queue.append([nx, ny])
                    graph[nx][ny] = 0


case = int(input())
graph = []
RBG_graph = []
for i in range(case):
    temp = input().rstrip()
    graph.append(list(temp))
    RBG_graph.append(list(temp))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

normal = 0
RGB = 0
for i in range(case):
    for j in range(case):
        if graph[i][j] != 0:
            normal += 1
            bfs(i, j, False, graph[i][j])

        if RBG_graph[i][j] != 0:
            RGB += 1
            bfs(i, j, True, RBG_graph[i][j])


print(normal, RGB)
