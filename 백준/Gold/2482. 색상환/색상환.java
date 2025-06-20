import com.sun.source.tree.Tree;
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
    static int n,k;
    static int[][] dp = new int[1001][1001];
    static int MOD = 1_000_000_003;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());

        for (int i = 0; i <= n; i++){
            dp[i][0] = 1;
            if (i >= 1) dp[i][1] = i;
        }
        for (int i = 2; i <= n; i++){
            for (int j = 2; j <= n; j++){
                dp[i][j] = (dp[i-1][j] + dp[i-2][j-1]) % MOD;
            }
        }
        int ans = (dp[n-1][k] + dp[Math.max(n - 3, 0)][k-1]) % MOD;
        System.out.println(ans);
    }
}
