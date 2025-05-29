import java.io.*;
import java.util.*;

public class Main {
    static int[] dp = new int[1000001];

    static void dfs(int here){
        if (here == 0) return;
        System.out.print(here + " ");
        if (here % 3 == 0 && dp[here] == (dp[here / 3] + 1)) dfs(here / 3);
        else if (here % 2 == 0 && dp[here] == (dp[here / 2] + 1)) dfs(here / 2);
        else if (here - 1 >= 0 && dp[here] == (dp[here - 1] + 1)) dfs(here - 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Arrays.fill(dp, 1000000);
        dp[1] = 0;
        for (int i = 1; i <= n; i++){
            dp[i] = Math.min(dp[i],dp[i-1] + 1);
            if (i % 2 == 0) {
                dp[i] = Math.min(dp[i], dp[i / 2] + 1);
            }
            if (i % 3 == 0) {
                dp[i] = Math.min(dp[i], dp[i / 3] + 1);
            }
        }
        System.out.println(dp[n]);
        dfs(n);
    }
}
