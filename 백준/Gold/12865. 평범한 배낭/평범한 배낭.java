import java.io.*;
import java.util.*;

public class Main {
    static int[] weights = new int[101];
    static int[] values = new int[101];
    static int[][] dp = new int[101][100001];
    static int n,k;
    static int dfs(int cur, int w){
        if (cur == 0 || w == 0) return 0;
        if (dp[cur][w] != 0) return dp[cur][w];
        if (weights[cur -1] > w)
            return dp[cur][w] = dfs(cur - 1, w);
        else return dp[cur][w] = Math.max(dfs(cur - 1, w - weights[cur - 1]) + values[cur -1], dfs(cur - 1, w));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int w = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            weights[i] = w;
            values[i] = v;
        }
        System.out.println(dfs(n, k));
    }
}
