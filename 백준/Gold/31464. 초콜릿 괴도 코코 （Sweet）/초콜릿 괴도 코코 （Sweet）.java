import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static char[][] arr = new char[41][41];
    static List<int[]> res = new ArrayList<>();
    static int n;
    static int[] dx = new int[]{1,0,-1,0};
    static int[] dy = new int[]{0,1,0,-1};

    static boolean isTree(){
        Queue<int[]> q = new LinkedList<>();
        boolean[][] vis = new boolean[n + 1][n + 1];

        int node = 0;
        int edge = 0;

        boolean found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == '#') {
                    q.add(new int[]{i, j});
                    vis[i][j] = true;
                    found = true;
                    break;
                }
            }
        }

        if (q.isEmpty()) return false;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            node++;

            int x = cur[0], y = cur[1];
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (arr[nx][ny] != '#') continue;
                edge++;
                if (!vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.add(new int[]{nx, ny});
                }
            }
        }

        int total = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (arr[i][j] == '#') total++;
        if (total != node) return false;

        edge /= 2;
        return edge == node - 1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String input = br.readLine();
            for (int j = 0; j < n; j++) {
                arr[i][j] = input.charAt(j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] != '#')
                    continue;

                // 한 칸 떼어내기
                arr[i][j] = '.';

                // 트리인지 검사
                if (isTree()) {
                    res.add(new int[]{i + 1, j + 1});
                }

                // 복원
                arr[i][j] = '#';
            }
        }
        System.out.println(res.size());
        for (int[] a : res){
            System.out.println(a[0] + " " + a[1]);
        }
    }
}
