import com.sun.source.tree.Tree;
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
    static int n,m,c;
    static int[] arr = new int[15];
    static int[][][] dp = new int[11][21][1 << 14]; // dp[가방 idx][현재 capa][사용 보석집합]

    static int dfs(int idx, int w, int gems){
        if (idx == m ){
            return 0;
        }
        if (dp[idx][w][gems] != 0) return dp[idx][w][gems];
        dp[idx][w][gems] = Math.max(dp[idx][w][gems], dfs(idx + 1, c, gems));
        for (int i = 0; i < n; i++){
            // 보석 안쓴거면 넣어본다.
            if ((gems & (1 << i)) == 0){
                if (w - arr[i] >= 0)
                    dp[idx][w][gems] = Math.max(dp[idx][w][gems], dfs(idx, w - arr[i], gems | (1 << i)) + 1);
            }
        }
        return dp[idx][w][gems];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        System.out.println(dfs(0, c,0));
    }
}
