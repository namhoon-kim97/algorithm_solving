import static java.lang.System.exit;

import java.util.*;
import java.io.*;

public class Main {
    static int[][][] dp = new int[1001][31][3]; // dp[idx][w][tree]
    static int[] b = new int[1001];
    static int t,w;

    static int go(int idx, int cnt, int tree){
        if (cnt < 0) return Integer.MIN_VALUE;
        if (idx == t) return 0;
        if (dp[idx][cnt][tree] != 0) return dp[idx][cnt][tree];
        int plus = (tree == (b[idx] - 1) ? 1 : 0);
        return dp[idx][cnt][tree] = Math.max(go(idx + 1, cnt - 1, tree^1), go(idx + 1, cnt,tree)) + plus;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        t = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());
        for (int i = 0; i < t; i++)
            b[i] = Integer.parseInt(br.readLine());

        System.out.println(Math.max(go(0,w,0), go(0,w-1,1)));
    }
}