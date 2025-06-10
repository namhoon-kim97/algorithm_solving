import com.sun.source.tree.Tree;
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
    static boolean[][] dp = new boolean[2501][2501];
    static char[] A = new char[2501];
    static int[] newDp = new int[2501];
    static int n,res;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //StringTokenizer st = new StringTokenizer(br.readLine());
        String is = br.readLine();
        n = is.length();
        for (int i = 1; i <= n; i++)
            A[i] = is.charAt(i - 1);
        for (int i = 1; i <= n; i++){
            dp[i][i] = true;
            newDp[i] = 1000000;
        }

        for (int i = 1; i < n; i++)
            if (A[i] == A[i + 1]) dp[i][i+1] = true;

        for (int len = 3; len <= n; len++){
            for (int i = 1; i + len - 1 <= n; i++){
                int j = i + len - 1;
                if (A[i] == A[j] && dp[i + 1][j - 1]) dp[i][j] = true;
            }
        }

        for (int en = 1; en <= n; en++){
            for (int st = 1; st <= en; st++){
                if (dp[st][en]){
                    newDp[en] = Math.min(newDp[st - 1] + 1, newDp[en]);
                }
            }
        }

        System.out.println(newDp[n]);
    }
}
