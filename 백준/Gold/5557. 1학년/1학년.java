import com.sun.source.tree.Tree;
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
    static long[][] dp = new long[104][21];
    static int[] arr = new int[101];
    static int n;

    static long dfs(int num, int cnt){
        if (num < 0 || num > 20) return 0;
        if (cnt == n - 1) {
            if (num == arr[n-1]) return 1;
            return 0;
        }
        if (dp[cnt][num] != -1) return dp[cnt][num];
        long result = 0;
        result += dfs(num + arr[cnt], cnt + 1);
        result += dfs(num - arr[cnt], cnt + 1);
        return dp[cnt][num] = result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            Arrays.fill(dp[i], -1);
        }

        System.out.println(dfs(arr[0],1));
    }
}
