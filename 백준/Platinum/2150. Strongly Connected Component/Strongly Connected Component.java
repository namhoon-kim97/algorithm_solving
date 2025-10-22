import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int V,E;
    static ArrayList<Integer>[] g, gr;
    static boolean[] vis;
    static Deque<Integer> order = new ArrayDeque<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        g = new ArrayList[V + 1];
        gr = new ArrayList[V + 1];

        for (int i = 1; i <= V; i++){
            g[i] = new ArrayList<>();
            gr[i] = new ArrayList<>();
        }

        for (int i = 0; i < E; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            g[a].add(b);
            gr[b].add(a);
        }

        vis = new boolean[V + 1];
        for (int i = 1; i <= V; i++)
            if (!vis[i]) dfs1(i);

        vis = new boolean[V + 1];
        ArrayList<ArrayList<Integer>> sccs = new ArrayList<>();
        while(!order.isEmpty()){
            int v = order.removeLast();
            if (!vis[v]){
                ArrayList<Integer> comp = new ArrayList<>();
                dfs2(v,comp);
                Collections.sort(comp);
                sccs.add(comp);
            }
        }
        sccs.sort((Comparator.comparingInt(list -> list.get(0))));
        StringBuilder sb = new StringBuilder();
        sb.append(sccs.size()).append('\n');
        for (ArrayList<Integer> comp : sccs){
            for (int x : comp) sb.append(x).append(' ');
            sb.append(-1).append('\n');
        }
        System.out.println(sb);
    }

    static void dfs1(int st){
        vis[st] = true;
        for (int nxt : g[st]){
            if (!vis[nxt]){
                dfs1(nxt);
            }
        }
        order.addLast(st);
    }

    static void dfs2(int st, ArrayList<Integer> comp){
        vis[st] = true;
        comp.add(st);
        for (int nxt : gr[st]){
            if (!vis[nxt]){
                dfs2(nxt,comp);
            }
        }
    }
}
