import com.sun.source.tree.Tree;
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
    static int cnt1,cnt2;
    static int[] dp = new int[41];
    static void fibo(int n){
        if (n == 1 || n == 2) {
            cnt1++;
            return;
        }
        fibo(n - 1);
        fibo(n-2);
    }
    static void fibonacci(int n){
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++){
            dp[i] = dp[i -1] + dp[i-2];
            cnt2++;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(br.readLine());
        fibo(n);
        fibonacci(n);
        System.out.print(cnt1 + " " + cnt2);
    }
}
