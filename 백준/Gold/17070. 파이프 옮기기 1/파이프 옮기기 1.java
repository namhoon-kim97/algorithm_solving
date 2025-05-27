import java.util.*;
import java.io.*;

public class Main {
    static int[][] board = new int[16][16];
    // dp[i][j][dir] 은 (i,j) 위치에 dir(가로,세로,대각선)로 올 경우의 수
    static int[][][] dp = new int[16][16][3]; // 0 가로, 1 세로, 2 대각선
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        for (int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++)
                board[i][j] = Integer.parseInt(st.nextToken());
        }
        dp[0][1][0] = 1;
        for (int i = 0; i < n; i++){
            for (int j = 1; j < n; j++){
                if (board[i][j] == 0){
                    dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
                    if (i > 0)
                        dp[i][j][1] += dp[i-1][j][1] + dp[i-1][j][2];
                    if (i > 0 && board[i - 1][j] == 0 && board[i][j-1] == 0)
                        dp[i][j][2] += dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
                }

            }
        }
        System.out.println(dp[n-1][n-1][0] + dp[n-1][n-1][1] + dp[n-1][n-1][2]);
    }
}