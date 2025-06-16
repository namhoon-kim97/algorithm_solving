import com.sun.source.tree.Tree;
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
    static String MAX_STR = "1".repeat(51);
    static String[] dp = new String[101];
    static int[] arr = new int[]{6,2,5,5,4,5,6,3,7,6};

    static String compareString(String a, String b){
        if (a.length() == b.length()){
            if (a.compareTo(b) < 0) return a;
            else return b;
        }
        if (a.length() < b.length()) return a;
        else return b;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < 101; i++)
            dp[i] = MAX_STR;
        dp[0] = "";
        // 최솟값
        for (int j = 2; j < 101; j++){
            for (int k = 0; k < 10; k++){
                if (j - arr[k] < 0) continue;
                if (k == 0 && dp[j - arr[k]].equals("")) continue;
                dp[j] = compareString(dp[j], dp[j - arr[k]] + k);
            }
        }
        for (int i = 0; i < t; i++){
            int n = Integer.parseInt(br.readLine());

            System.out.print(dp[n] + " ");

            // 최댓값
            if (n % 2 != 0) {
                System.out.print(7);
            } else {
                System.out.print(1);
            }
            for (int j = 0; j < n / 2 - 1; j++) {
                System.out.print(1);
            }
            System.out.println();
        }
    }
}
