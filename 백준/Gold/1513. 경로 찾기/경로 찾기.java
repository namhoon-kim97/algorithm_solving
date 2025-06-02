import java.io.*;
import java.util.*;

public class Main {
    static int[][][][] dp = new int[51][51][51][51];
    static int[][] board = new int[51][51];
    static int MOD = 1000007;
    static int n,m,c;

    static int go(int x, int y, int cnt , int prev){
        if (x > n || y > m) return 0;
        if (x == n && y == m){
            if (board[x][y] == 0 && cnt == 0) return 1;
            if (board[x][y] > prev && cnt == 1) return 1;
            return 0;
        }
        if (dp[x][y][cnt][prev] != -1) return dp[x][y][cnt][prev];
        dp[x][y][cnt][prev] = 0;
        if (board[x][y] == 0)
            dp[x][y][cnt][prev] = (go(x+1,y,cnt, prev) + go(x,y+1,cnt, prev)) % MOD;
        else if (board[x][y] > prev  && cnt >= 1)
            dp[x][y][cnt][prev] = (go(x+1,y,cnt-1, board[x][y]) + go(x,y+1,cnt-1, board[x][y])) % MOD;
        return dp[x][y][cnt][prev];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= c; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            board[x][y] = i;
        }
        for (int i = 0; i < 51; i++) {
            for (int j = 0; j < 51; j++) {
                for (int k = 0; k < 51; k++) {
                    for (int l = 0; l < 51; l++) {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        for (int i = 0; i <= c; i++) {
            System.out.print(go(1,1,i,0) + " ");
        }
    }
}
