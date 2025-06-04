import java.io.*;
import java.util.*;

public class Main {
    static int[] attack = new int[21];
    static int[] pleasure = new int[21];
    static int[][] dp = new int[21][101];

    static int dfs(int cnt, int hp){
        if (cnt == 0 || hp == 0) return 0;
        if (dp[cnt][hp] != -1) return dp[cnt][hp];
        if (attack[cnt] >= hp) return dp[cnt][hp] = dfs(cnt - 1, hp);
        else return dp[cnt][hp] = Math.max(dfs(cnt - 1, hp - attack[cnt]) + pleasure[cnt], dfs(cnt - 1, hp));
    }

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
        for (int i = 1 ; i <= n; i++)
            for (int j = 1; j <= 100; j++)
                dp[i][j] = -1;

        System.out.println(dfs(n,100));
    }
}
