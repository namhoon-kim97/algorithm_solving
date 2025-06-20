import com.sun.source.tree.Tree;
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
    static int n,k;
    static long[][][] dp = new long[1001][1001][4];
    static int MOD = 1_000_000_003;

    static long dfs(int idx, int limit, boolean firstSelected, boolean prevSelected){
        if (limit > k) return 0;
        if (idx == n){
            if (limit == k && !(firstSelected && prevSelected)) return 1;
            return 0;
        }

        int first = firstSelected ? 1 : 0;
        int prev = prevSelected ? 1 : 0;
        if (dp[idx][limit][first * 2 + prev] != -1) return dp[idx][limit][first * 2 + prev];

        long res = 0;
        // 현재 색을 선택하는 경우 (이전 색을 선택하지 않았을 때만 가능)
        if (!prevSelected) {
            boolean newFirstSelected = firstSelected || (idx == 0);
            res += dfs(idx + 1, limit + 1, newFirstSelected, true);
            res %= MOD;
        }
        // 현재 색을 선택하지 않는 경우
        res += dfs(idx + 1, limit, firstSelected, false);
        res %= MOD;

        return dp[idx][limit][first * 2 + prev] = res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());
        if (k > n / 2) {
            System.out.println(0);
            return;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < 4; k++)
                    dp[i][j][k] = -1;
        System.out.println(dfs(0,0, false,false));
    }
}
