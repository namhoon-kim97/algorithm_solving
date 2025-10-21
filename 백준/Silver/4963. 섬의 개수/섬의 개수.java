import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] dx = {1,0,-1,0,1,-1,1,-1};
    static int[] dy = {0,1,0,-1,1,-1,-1,1};

    static int solution(int[][] board){
        int n = board.length;
        int m = board[0].length;
        boolean[][] vis = new boolean[n+1][m+1];
        Queue<int[]> q =  new LinkedList<>();
        int ret = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!vis[i][j] && board[i][j] == 1){
                    ret++;
                    vis[i][j] = true;
                    q.add(new int[]{i,j});
                    while (!q.isEmpty()){
                        int[] cur = q.poll();
                        for (int dir = 0; dir < 8; dir++){
                            int nx = cur[0] + dx[dir];
                            int ny = cur[1] + dy[dir];
                            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            if (vis[nx][ny] || board[nx][ny] == 0) continue;
                            vis[nx][ny] = true;
                            q.add(new int[]{nx,ny});
                        }
                    }
                }
            }
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        while (true){
            st = new StringTokenizer(br.readLine());
            int w = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());
            if (w == 0 && h == 0) break;
            int[][] board = new int[h+1][w+1];
            for (int i = 0; i < h; i++){
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < w; j++){
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            System.out.println(solution(board));
        }
    }
}
