import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static final int N = 4001;
    static List<int[]>[] adj = new ArrayList[N];

    static int[] wolfFast = new int[4001];
    static int[] wolfSlow = new int[4001];
    static int[] fox = new int[4001];
    static {
        for (int i = 0; i < N; i++) {
            adj[i] = new ArrayList<>();
            wolfFast[i] = Integer.MAX_VALUE;
            wolfSlow[i] = Integer.MAX_VALUE;
            fox[i] = Integer.MAX_VALUE;
        }
    }

    static void dijkstraFox() {
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[0])); // 거리, 시작점
        fox[1] = 0;
        pq.add(new int[]{0, 1});

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int d = cur[0];
            int u = cur[1];
            if (d != fox[u]) continue;

            for (int[] e : adj[u]) {
                int v = e[1];
                int w = e[0];
                int nd = d + w;
                if (nd < fox[v]) {
                    fox[v] = nd;
                    pq.add(new int[]{nd, v});
                }
            }
        }
    }

    static void dijkstraWolf(){
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0])); // 거리, 시작점, 이전 속도(0 0.5배, 1 2배)
        wolfFast[1] = 0;
        pq.add(new int[]{0,1,0});
        while(!pq.isEmpty()){
            int[] cur = pq.poll();
            int d = cur[0], u = cur[1], s = cur[2];
            if ((s == 0 && d != wolfFast[u]) || (s == 1 && d != wolfSlow[u])) continue;
            for (int[] nxt : adj[cur[1]]){
                int v = nxt[1];
                int cost = (s == 0) ? (nxt[0] / 2) : (nxt[0] * 2);
                int nd = cost + d;

                if (s == 0) {
                    if (nd < wolfSlow[v]) {
                        wolfSlow[v] = nd;
                        pq.add(new int[]{nd, v, 1});
                    }
                }
                else {
                    if (nd < wolfFast[v]) {
                        wolfFast[v] = nd;
                        pq.add(new int[]{nd, v, 0});
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        for (int i = 0; i < m; i++){
            int a,b,d;
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken()) * 2;
            adj[a].add(new int[]{d,b});
            adj[b].add(new int[]{d,a});
        }

        // 하나의 bfs 돌려서 달빛 늑대 도착 시간 채우고
        // 다음 bfs 돌려서 달빛 여우 도착 시간이 늑대보다 빠르면 cnt++

        dijkstraWolf();
        dijkstraFox();
        int answer = 0;
        for (int i = 2; i <= n; i++) {
            long wolfBest = Math.min(wolfFast[i], wolfSlow[i]);
            if (fox[i] < wolfBest) answer++;
        }
        System.out.println(answer);
    }
}
