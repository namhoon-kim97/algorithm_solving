import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] dx = {-2,-2,0,0,2,2};
    static int[] dy = {-1,1,-2,2,-1,1};
    static int[][] vis = new int[201][201];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int r1 = Integer.parseInt(st.nextToken());
        int c1 = Integer.parseInt(st.nextToken());
        int r2 = Integer.parseInt(st.nextToken());
        int c2 = Integer.parseInt(st.nextToken());
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{r1,c1});
        while (!q.isEmpty()){
            int[] cur = q.poll();
            if (cur[0] == r2 && cur[1] == c2){
                System.out.println(vis[cur[0]][cur[1]]);
                return;
            }
            for (int i = 0; i < 6; i++){
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (vis[nx][ny] != 0) continue;
                vis[nx][ny] = vis[cur[0]][cur[1]] + 1;
                q.add(new int[]{nx,ny});
            }
        }
        System.out.println(-1);
    }
}
