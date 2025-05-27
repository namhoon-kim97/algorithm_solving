import static java.lang.System.exit;

import java.util.*;
import java.io.*;

public class Main {
    static char[][] board = new char[51][51];
    static int[][] dp = new int[51][51];
    static boolean[][] vis = new boolean[51][51];
    static int n,m;

    static int solution(int x, int y){
        if (x < 0 || y < 0 || x >= n || y >= m || board[x][y] == 'H') return 0;
        if (vis[x][y]) {
            System.out.println(-1);
            exit(0);
        }
        if (dp[x][y] != 0) return dp[x][y];
        vis[x][y] = true;
        int cur = board[x][y] - '0';
        dp[x][y] = Math.max(dp[x][y],solution(x + cur, y) + 1);
        dp[x][y] = Math.max(dp[x][y],solution(x - cur, y) + 1);
        dp[x][y] = Math.max(dp[x][y],solution(x, y + cur) + 1);
        dp[x][y] = Math.max(dp[x][y],solution(x, y - cur) + 1);
        vis[x][y] = false;
        return dp[x][y];
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++){
            String temp = br.readLine();
            for (int j = 0; j < m; j++){
                board[i][j] = temp.charAt(j);
            }
        }
        System.out.println(solution(0,0));
    }
}