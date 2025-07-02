import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] dp = new int[31][31];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 1; i < 30; i++){
            dp[i][i] = 1;
            dp[i][1] = i;
        }
        for (int i = 2; i < 30; i++){
            for (int j = 2; j < i; j++){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }

        int t = Integer.parseInt(br.readLine());
        StringTokenizer st;
        while (t-- > 0){
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            System.out.println(dp[m][n]);
        }

    }
}
