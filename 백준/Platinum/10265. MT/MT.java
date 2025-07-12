import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n, k;
    static List<Integer>[] graph = new ArrayList[1001];
    static List<Integer>[] revGraph = new ArrayList[1001];
    static boolean[] vis = new boolean[1001];
    static Stack<Integer> stack = new Stack<>();
    static int[] sccId = new int[1001];
    static int[] sccSize = new int[1001];
    static List<Integer>[] sccGraph = new ArrayList[1001];
    static int[] indegree = new int[1001];
    static boolean[] visited = new boolean[1001];
    static int[] dp = new int[1001];

    static void dfs1(int node) {
        vis[node] = true;
        for (int nxt : graph[node]) {
            if (!vis[nxt]) dfs1(nxt);
        }
        stack.push(node);
    }

    static void dfs2(int node, int id) {
        vis[node] = true;
        sccId[node] = id;
        sccSize[id]++;
        for (int nxt : revGraph[node]) {
            if (!vis[nxt]) dfs2(nxt, id);
        }
    }

    static int dfsBundle(int u) {
        if (visited[u]) return 0;
        visited[u] = true;
        int total = sccSize[u];
        for (int v : sccGraph[u]) {
            total += dfsBundle(v);
        }
        return total;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
            revGraph[i] = new ArrayList<>();
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            int to = Integer.parseInt(st.nextToken());
            graph[to].add(i);
            revGraph[i].add(to);
        }

        Arrays.fill(vis, false);
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs1(i);
        }

        Arrays.fill(vis, false);
        int sccCnt = 0;
        while (!stack.isEmpty()) {
            int top = stack.pop();
            if (!vis[top]) {
                dfs2(top, sccCnt++);
            }
        }

        for (int i = 0; i < sccCnt; i++) sccGraph[i] = new ArrayList<>();

        for (int u = 1; u <= n; u++) {
            for (int v : graph[u]) {
                int su = sccId[u];
                int sv = sccId[v];
                if (su != sv && !sccGraph[su].contains(sv)) {
                    sccGraph[su].add(sv);
                    indegree[sv]++;
                }
            }
        }

        List<int[]> bundles = new ArrayList<>();
        for (int i = 0; i < sccCnt; i++) {
            if (indegree[i] == 0) {
                visited = new boolean[sccCnt];
                int maxSize = dfsBundle(i);
                bundles.add(new int[]{sccSize[i], maxSize});
            }
        }

        for (int[] bundle : bundles) {
            int minSize = bundle[0];
            int maxSize = bundle[1];

            for (int j = k; j >= 0; j--) {
                for (int w = minSize; w <= maxSize; w++) {
                    if (j - w >= 0) {
                        dp[j] = Math.max(dp[j], dp[j - w] + w);
                    }
                }
            }
        }

        System.out.println(dp[k]);
    }
}
