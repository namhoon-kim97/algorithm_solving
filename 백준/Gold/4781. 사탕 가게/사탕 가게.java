import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            int[] dp = new int[10001];
            int[] price = new int[5001];
            int[] values = new int[5001];
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n,m;
            n = Integer.parseInt(st.nextToken());
            m = (int) (Double.parseDouble(st.nextToken()) * 100 + 0.5);
            if (n == 0) break;
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                int c = Integer.parseInt(st.nextToken());
                int p = (int) (Double.parseDouble(st.nextToken()) * 100 + 0.5);
                values[i] = c;
                price[i] = p;
            }
            for (int i = 0; i < n; i++){
                for (int j = price[i]; j <= m; j++){
                    dp[j] = Math.max(dp[j], dp[j - price[i]] + values[i]);
                }
            }
            System.out.println(dp[m]);
        }

    }
}
