import java.util.*;
import java.io.*;

public class Main {
    static class Pair{
        int x,y;
        public Pair (int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    static int n,m;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static int res = Integer.MAX_VALUE;
    static int[][] arr = new int[51][51];

    public static void bfs(List<Pair> selected){
        boolean[][] vis = new boolean[n][n];
        int[][] temp = new int[n][n];
        int[][] time = new int[n][n];

        // 깊은 복사 + 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = arr[i][j];
                time[i][j] = -1; // 아직 감염되지 않음
                if (temp[i][j] == 2) temp[i][j] = -1; // 비활성 바이러스
            }
        }

        Queue<Pair> q = new LinkedList<>();
        for (Pair p : selected) {
            q.add(p);
            vis[p.x][p.y] = true;
            time[p.x][p.y] = 0; // 활성 시작은 0초
        }

        while (!q.isEmpty()) {
            Pair cur = q.poll();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (vis[nx][ny] || temp[nx][ny] == 1) continue;

                vis[nx][ny] = true;
                time[nx][ny] = time[cur.x][cur.y] + 1;
                q.add(new Pair(nx, ny));
            }
        }

        int maxTime = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 빈 칸이 감염되지 않았다면 실패
                if (arr[i][j] == 0 && time[i][j] == -1)
                    return;
                // 최대 시간 갱신 (비활성 바이러스는 제외)
                if (arr[i][j] == 0)
                    maxTime = Math.max(maxTime, time[i][j]);
            }
        }

        res = Math.min(res,maxTime);
    }



    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        List<Pair> virus = new ArrayList<>();
        for (int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 2)
                    virus.add(new Pair(i,j));
            }
        }

        // m개의 활성바이러스 조합
        // 퍼뜨림
        // 바이러스 확인
        // 최소 시간 갱신
        for (int i = 0; i < (1 << virus.size()); i++){
           if (Integer.bitCount(i) != m) continue;
           List<Pair> selected = new ArrayList<>();
           for (int j = 0; j < virus.size(); j++){
               if ((i & (1 << j)) != 0)
                   selected.add(virus.get(j));
           }
           bfs(selected);
        }
        if (res == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else
            System.out.println(res);
    }
}