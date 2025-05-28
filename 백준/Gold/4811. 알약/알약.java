import java.util.*;
import java.io.*;

public class Main {
    static int n = 1;
    static long[][] dp = new long[31][31];

    static long go(int whole, int not_whole){
        if (whole == 0 && not_whole == 0) return 1;
        if (dp[whole][not_whole] != 0) return dp[whole][not_whole];
        if (whole > 0) dp[whole][not_whole] += go(whole - 1, not_whole + 1);
        if (not_whole > 0) dp[whole][not_whole] += go(whole, not_whole - 1);
        return dp[whole][not_whole];
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true){
            n = Integer.parseInt(br.readLine());
            if (n == 0) break;
            System.out.println(go(n,0));
        }
    }
}