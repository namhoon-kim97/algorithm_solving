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

        Arrays.sort(coin, 0,n);
        dp[0] = 1;
        for (int i = 0; i < n; i++){
            for (int j = coin[i]; j <= k; j++){
                dp[j] += dp[j - coin[i]];
            }
//            for (int m = 1; m <= k; m++) {
//                System.out.print(dp[m] + " ");
//            }
//            System.out.println("");
        }

        System.out.println(dp[k]);
    }
}
