import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] p = new int[101];
    static Integer BASE = 100;
    static Map<Integer, Integer> map = new HashMap<>();
    static List<int[]> edges = new ArrayList<>();
    static int[][] board = new int[11][11];
    static boolean[][] vis = new boolean[11][11];
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,-1,0,1};
    static int n,m;

    static void bfs(int x, int y, int num){
        vis[x][y] = true;
        board[x][y] = num;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{x,y});
        while (!q.isEmpty()){
            int[] cur = q.poll();
            for (int dir = 0; dir < 4; dir++){
                int nx = cur[0] + dx[dir];
                int ny = cur[1] + dy[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (vis[nx][ny] || board[nx][ny] == 0) continue;
                vis[nx][ny] = true;
                board[nx][ny] = num;
                q.add(new int[]{nx,ny});
            }
        }
    }

    static void addEdges(){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int st = board[i][j];
                if (st >= 2){
                    for (int dir = 0; dir < 4; dir++){
                        int nx = i;
                        int ny = j;
                        int len = 0;
                        while (true){
                            nx += dx[dir];
                            ny += dy[dir];
                            if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                            if (board[nx][ny] == st) break;
                            if (board[nx][ny] == 0){
                                len++; continue;
                            }
                            if (board[nx][ny] != st){
                                if (len >= 2){
                                    int en = board[nx][ny];
                                    int u = Math.min(st, en), v = Math.max(st, en);
                                    int key = u * BASE + v;
                                    Integer prev = map.get(key);
                                    if (prev == null || len < prev) {
                                        map.put(key, len);
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    static int find(int x){
        if (p[x] < 0) return x;
        return p[x] = find(p[x]);
    }

    static boolean isDiffGroup(int u, int v){
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (p[v] < p[u]){
            int temp = u;
            u = v;
            v = temp;
        }
        if (p[u] == p[v]) p[u]--;
        p[v] = u;
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = java.lang.Integer.parseInt(st.nextToken());
        m = java.lang.Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++){
                board[i][j] = java.lang.Integer.parseInt(st.nextToken());
            }
        }
        int num = 2;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!vis[i][j] && board[i][j] == 1){
                    bfs(i,j,num);
                    num += 1;
                }
            }
        }

        addEdges();
        for (Map.Entry<Integer, Integer> e : map.entrySet()){
            int key = e.getKey();
            int u = key / BASE;
            int v = key % BASE;
            edges.add(new int[]{u, v, e.getValue()});
        }
        edges.sort((a,b) ->{
            return Integer.compare(a[2], b[2]);
        });
        Arrays.fill(p, -1);

        int used = 0;
        int total = 0;
        for (int[] e: edges){
            if (isDiffGroup(e[0], e[1])){
                total += e[2];
                used++;
                if (used == num - 3) break;
            }
        }

        if (num <= 1) {
            System.out.println(0);
        } else if (used == num - 3) {
            System.out.println(total);
        } else {
            System.out.println(-1);
        }
    }
}
