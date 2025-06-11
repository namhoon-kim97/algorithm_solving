import com.sun.source.tree.Tree;
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
    static int n,k;
    static int[][] dp = new int[101][100001];
    static List<Pair> walk = new ArrayList<>();
    static List<Pair> bi = new ArrayList<>();
    static class Pair{
        int t,w;
        public Pair(int t, int w){
            this.t = t;
            this.w = w;
        }
    }

    static int dfs(int idx, int limit){
        if (idx == n) return 0;
        //if (limit < 0) return -1000000;
        if (dp[idx][limit] != -1000000) return dp[idx][limit];

        if (limit - walk.get(idx).t >= 0)
            dp[idx][limit] = Math.max(dp[idx][limit], dfs(idx + 1, limit - walk.get(idx).t) + walk.get(idx).w);

        if (limit - bi.get(idx).t >= 0)
            dp[idx][limit] = Math.max(dp[idx][limit], dfs(idx + 1, limit - bi.get(idx).t) + bi.get(idx).w);
        return dp[idx][limit] ;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            walk.add(new Pair(Integer.parseInt(st.nextToken()),  Integer.parseInt(st.nextToken())));
            bi.add(new Pair(Integer.parseInt(st.nextToken()),  Integer.parseInt(st.nextToken())));
        }
        for (int[] row : dp) Arrays.fill(row, -1000000);
        System.out.println(dfs(0, k));
    }
}
