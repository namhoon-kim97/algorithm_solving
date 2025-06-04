import java.io.*;
import java.util.*;

public class Main {
    static int[] attack = new int[21];
    static int[] pleasure = new int[21];
    static int[][] dp = new int[101][21];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++){
            attack[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++){
            pleasure[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= 100; i++){
            for (int j = 1; j <= n; j++){
                if(i - attack[j] > 0)
                    dp[i][j] = Math.max(dp[i][j-1], dp[i-attack[j]][j-1] + pleasure[j]);
                else dp[i][j] = dp[i][j-1];
            }
        }
        System.out.println(dp[100][n]);
    }
}
