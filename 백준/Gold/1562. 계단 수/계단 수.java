import java.util.*;
import java.io.*;

public class Main {
    static long[][][] dp = new long[101][11][1024]; // dp[i][j][mask] = 길이 i인 수, 마지막 숫자가 j로 끝나는 계단수의 개수 , mask는 사용숫자 판별용
    static int MOD = 1_000_000_000;

    public static long solution(int n){
        if (n < 10) return 0;

        for (int i = 1; i <= 9; i++)
            dp[1][i][1 << i] = 1;

        for (int i = 2; i <= n; i++){
            for (int j = 0; j <= 9; j++){
                for (int mask = 0; mask < 1024; mask++){
                    if (dp[i - 1][j][mask] == 0) continue;
                    if (j > 0){
                        int nextMask = mask | (1 << (j - 1));
                        dp[i][j - 1][nextMask] = (dp[i][j - 1][nextMask] + dp[i - 1][j][mask]) % MOD;
                    }
                    if (j < 9){
                        int nextMask = mask | (1 << (j + 1));
                        dp[i][j + 1][nextMask] = (dp[i][j + 1][nextMask] + dp[i - 1][j][mask]) % MOD;
                    }
                }
            }
        }

        long res = 0;
        int full = (1 << 10) - 1;
        for (int i = 0; i <= 9; i++){
            res = (res + dp[n][i][full]) % MOD;
        }
        return res;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        System.out.println(solution(n));
    }
}