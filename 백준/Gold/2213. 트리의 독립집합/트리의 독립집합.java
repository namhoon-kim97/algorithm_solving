import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] weights;
    static List<Integer>[] tree;
    static int[][] dp;
    static boolean[] visited;
    static List<Integer> answer = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        weights = new int[n + 1];
        dp = new int[n + 1][2];
        visited = new boolean[n + 1];
        tree = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) tree[i] = new ArrayList<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            weights[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            tree[u].add(v);
            tree[v].add(u);
        }

        dfs(1);
        int result = Math.max(dp[1][0], dp[1][1]);
        System.out.println(result);

        visited = new boolean[n + 1];
        track(1, dp[1][1] > dp[1][0]);
        Collections.sort(answer);
        for (int node : answer) System.out.print(node + " ");
    }

    static void dfs(int node) {
        visited[node] = true;
        dp[node][0] = 0;               // 선택하지 않은 경우
        dp[node][1] = weights[node];   // 선택한 경우

        for (int child : tree[node]) {
            if (!visited[child]) {
                dfs(child);
                dp[node][0] += Math.max(dp[child][0], dp[child][1]);
                dp[node][1] += dp[child][0];
            }
        }
    }

    static void track(int node, boolean isSelected) {
        visited[node] = true;
        if (isSelected) answer.add(node);

        for (int child : tree[node]) {
            if (!visited[child]) {
                if (isSelected) {
                    track(child, false);
                } else {
                    track(child, dp[child][1] > dp[child][0]);
                }
            }
        }
    }
}
