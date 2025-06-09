import com.sun.source.tree.Tree;
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
    static boolean[][] dp = new boolean[2001][2001];
    static int[] A = new int[2001];
    static int n,m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++)
            A[i] = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= n; i++){
            dp[i][i] = true;
        }

        for (int i = 1; i < n; i++)
            if (A[i] == A[i + 1]) dp[i][i+1] = true;

        for (int len = 3; len <= n; len++){
            for (int i = 1; i + len - 1 <= n; i++){
                int j = i + len - 1;
                if (A[i] == A[j] && dp[i + 1][j - 1]) dp[i][j] = true;
            }
        }


        m = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            if (dp[x][y]) {
                sb.append("1\n");
            } else {
                sb.append("0\n");
            }
        }
        System.out.println(sb);
    }
}
