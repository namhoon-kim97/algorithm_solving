import com.sun.source.tree.Tree;
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
    static double a,b;
    static int n = 18;
    static boolean[] isPrime = new boolean[21];
    static double[][][] dp = new double[21][21][21];

    static double go(int idx, int x, int y){
        if (idx == n) return isPrime[x] || isPrime[y] ? 1.0 : 0.0;
        if (dp[idx][x][y] > -0.5) return dp[idx][x][y];
        dp[idx][x][y] = 0.0;

        dp[idx][x][y] += go(idx + 1, x + 1, y) * a * (1-b);
        dp[idx][x][y] += go(idx + 1, x , y + 1) * (1- a) * b;
        dp[idx][x][y] += go(idx + 1, x , y) * (1- a) * (1-b);
        dp[idx][x][y] += go(idx + 1, x + 1, y+1) * a * b;
        return dp[idx][x][y];
    }

    static void era(){
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i <= 20; i++){
            for (int j = i + i; j <= 20; j += i){
                isPrime[j] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //StringTokenizer st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(br.readLine()) / 100.0;
        b = Integer.parseInt(br.readLine()) / 100.0;
        era();
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                for (int k = 0; k <= n; k++)
                    dp[i][j][k] = -1.0;
        System.out.println(go(0,0,0));
    }
}
