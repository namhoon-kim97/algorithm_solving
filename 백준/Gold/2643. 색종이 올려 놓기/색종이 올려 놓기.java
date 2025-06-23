import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static class Pair{
        int x,y;
        public Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    static int n;
    static List<Pair> papers = new ArrayList<>();
    static int[] dp = new int[101];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        for (int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            papers.add(new Pair(Math.max(r,c), Math.min(r,c)));
        }
        papers.sort(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if (o1.x != o2.x) return -Integer.compare(o1.x, o2.x);
                return -Integer.compare(o1.y, o2.y);
            }
        });

        for (int i = 0; i < n; i++){
            int cx = papers.get(i).x;
            int cy = papers.get(i).y;
            dp[i] = 1;
            for (int j = 0; j < i; j++){
                if (cx <= papers.get(j).x && cy <= papers.get(j).y){
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++)
            ans = Math.max(dp[i], ans);
        System.out.println(ans);
    }
}
