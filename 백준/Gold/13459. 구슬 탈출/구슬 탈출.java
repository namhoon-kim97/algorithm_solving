import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n,m;
    static char[][] board = new char[11][11];
    static boolean[][][][] visited;
    static int[] dx = {-1, 1,0, 0};
    static int[] dy = {0,0,-1,1};

    static class State {
        int rx, ry, bx, by, depth;
        State(int rx, int ry, int bx, int by, int depth){
            this.rx = rx; this.ry = ry; this.bx = bx; this.by = by; this.depth = depth;
        }
    }

    static class RollResult {
        int x, y, moved;
        boolean inHole;
        RollResult(int x, int y, int moved, boolean inHole){
            this.x = x; this.y = y; this.moved = moved; this.inHole = inHole;
        }
    }

    static boolean isRedFirst(int rx, int ry, int bx, int by, int dir){
        // U(0): x 작은 게 먼저 / D(1): x 큰 게 먼저
        // L(2): y 작은 게 먼저 / R(3): y 큰 게 먼저
        if (dir == 0) return rx < bx;
        if (dir == 1) return rx > bx;
        if (dir == 2) return ry < by;
        return ry > by; // dir == 3
    }

    static RollResult roll(int x, int y, int dir){
        int nx = x, ny = y, moved = 0;
        while (true) {
            int tx = nx + dx[dir], ty = ny + dy[dir];
            if (board[tx][ty] == '#') break;
            nx = tx; ny = ty; moved++;
            if (board[nx][ny] == 'O') return new RollResult(nx, ny, moved, true);
        }
        return new RollResult(nx, ny, moved, false);
    }

    static int bfs(int rx, int ry, int bx, int by){
        Queue<State> q = new LinkedList<>();
        q.offer(new State(rx, ry, bx, by, 0));
        visited[rx][ry][bx][by] = true;
        while (!q.isEmpty()){
            State cur = q.poll();
            if (cur.depth >= 10) continue;

            for (int dir = 0; dir < 4; dir++){
                boolean redFirst = isRedFirst(cur.rx, cur.ry, cur.bx, cur.by, dir);
                RollResult r,b;
                if (redFirst){
                    r = roll(cur.rx, cur.ry, dir);
                    b = roll(cur.bx, cur.by, dir);
                } else{
                    b = roll(cur.bx, cur.by, dir);
                    r = roll(cur.rx, cur.ry, dir);
                }
                if (b.inHole) continue;
                if (r.inHole) return 1;

                int nrx = r.x, nry = r.y, nbx = b.x, nby = b.y;
                if (nrx == nbx && nry == nby){
                    if (r.moved > b.moved) { // 더 많이 움직인 쪽을 한 칸 뒤로
                        nrx -= dx[dir]; nry -= dy[dir];
                    } else {
                        nbx -= dx[dir]; nby -= dy[dir];
                    }
                }
                if (!visited[nrx][nry][nbx][nby]){
                    visited[nrx][nry][nbx][nby] = true;
                    q.offer(new State(nrx, nry, nbx, nby, cur.depth + 1));
                }
            }
        }
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int rx=0, ry=0, bx=0, by=0;
        for (int i = 0; i < n; i++){
            String input = br.readLine();
            for (int j = 0; j < m; j++){
                board[i][j] = input.charAt(j);
                if (board[i][j] == 'R'){ rx = i; ry = j; board[i][j]='.'; }
                if (board[i][j] == 'B'){ bx = i; by = j; board[i][j]='.'; }
            }
        }
        visited = new boolean[n][m][n][m];
        System.out.println(bfs(rx, ry, bx, by));
    }
}
