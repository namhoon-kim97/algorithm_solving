import com.sun.source.tree.Tree;
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
    static int n,m,k;
    static int[][] dp = new int[16][16];
    static int[][] dp2 = new int[16][16];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        if (k == 0){
            dp[0][0] = 1;
            for (int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if (i > 0)
                        dp[i][j] += dp[i -1][j];
                    if (j > 0)
                        dp[i][j] += dp[i][j - 1];
                }
            }
            System.out.println(dp[n-1][m-1]);
        }
        else{
            int n2 = k / m;
            int m2 = k - (m * n2) - 1;
            dp2[0][0] = 1;
            for (int i = 0; i <= n2; i++){
                for(int j = 0; j <= m2; j++){
                    if (i > 0)
                        dp2[i][j] += dp2[i -1][j];
                    if (j > 0)
                        dp2[i][j] += dp2[i][j - 1];
                }
            }
            int first = dp2[n2][m2];
            dp2[n2][m2] = 1;
            for (int i = n2; i < n; i++){
                for(int j = m2; j < m; j++){
                    if (i > n2)
                        dp2[i][j] += dp2[i -1][j];
                    if (j > m2)
                        dp2[i][j] += dp2[i][j - 1];
                }
            }
            int second = dp2[n-1][m-1];
            System.out.println(first * second);
        }
    }
}
