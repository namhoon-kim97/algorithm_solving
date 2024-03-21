
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int[][][] arr = new int[105][105][105];
    static int[][][] dist = new int[105][105][105];
    static int[] dx = {1,0,-1,0,0,0};
    static int[] dy = {0,1,0,-1,0,0};
    static int[] dz = {0,0,0,0,1,-1};
    static class Triple{
        int x,y,z;
        Triple(int x, int y, int z){
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int m = Integer.parseInt(str[0]);
        int n = Integer.parseInt(str[1]);
        int h = Integer.parseInt(str[2]);

        Queue<Triple> queue = new LinkedList<>();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < n; j++) {
                str = br.readLine().split(" ");
                for (int k = 0; k < m; k++) {
                    arr[k][j][i] = Integer.parseInt(str[k]);
                    if (arr[k][j][i] == 1) queue.add(new Triple(k, j, i));
                    if (arr[k][j][i] == 0) dist[k][j][i] = -1;
                }
            }
        }



        while(!queue.isEmpty()){
            Triple cur = queue.poll();
            for (int i = 0; i < 6; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                int nz = cur.z + dz[i];
                if (nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h) continue;
                if (dist[nx][ny][nz] >= 0) continue;
                dist[nx][ny][nz] = dist[cur.x][cur.y][cur.z] + 1;
                queue.add(new Triple(nx, ny, nz));
            }
        }

        boolean flag = true;
        int cnt = -1;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    if (dist[k][j][i] == -1){
                        flag = false;
                        break;
                    }
                    cnt = Math.max(cnt, dist[k][j][i]);
                }
                if(!flag) break;
            }
            if(!flag) break;
        }

        if(!flag) System.out.println(-1);
        else System.out.println(cnt);
    }
}
