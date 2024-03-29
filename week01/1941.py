import sys
import queue

input = sys.stdin.readline

a = [input().strip() for _ in range(5)]
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

for i in range(5):
    for j in range(5):
        q = queue.Queue()
        q.put((i, j))
        if a[i][j] == "Y":
            ycnt = 1
        else:
            ycnt = 0
        ans = 0
        seven = []
        vis = [[False] * 5 for _ in range(5)]
        while not q.empty():
            cur = q.get()
            if len(seven) == 7:
                ans += 1
                break
            for i in range(4):
                nx = cur[0] + dx[i]
                ny = cur[1] + dy[i]
                if nx < 0 or ny < 0 or nx >= 5 or ny >= 5:
                    continue
                if vis[nx][ny]:
                    continue
                if a[nx][ny] == "Y":
                    ycnt += 1
                    if ycnt > 3:
                        continue
                vis[nx][ny] = True
                seven.append(a[nx][ny])
                q.put((nx, ny))

print(ans)
