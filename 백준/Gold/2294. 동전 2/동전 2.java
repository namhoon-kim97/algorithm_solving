import java.io.*;
import java.util.*;

public class Main {
    static int[] dp = new int[10001];
    static int[] coin = new int[101];
    static int n,k;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++)
            coin[i] = Integer.parseInt(br.readLine());

        Arrays.fill(dp, 1000000000);
        Arrays.sort(coin, 0,n);
        dp[0] = 0;
        for (int i = 0; i < n; i++){
            for (int j = coin[i]; j <= k; j++){
                dp[j] = Math.min(dp[j], dp[j - coin[i]] + 1);
            }
        }
        if (dp[k] == 1000000000)
            System.out.println(-1);
        else {
            System.out.println(dp[k]);
        }
    }
}
