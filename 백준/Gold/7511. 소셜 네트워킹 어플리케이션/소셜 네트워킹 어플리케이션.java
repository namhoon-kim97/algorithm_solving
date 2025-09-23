import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] p = new int[1000001];

    static int find(int x){
        if (p[x] < 0) return x;
        return p[x] = find(p[x]);
    }

    static void union(int a, int b){
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (p[b] < p[a]){
            int temp = a;
            a = b;
            b = temp;
        }
        if (p[a] == p[b])
            p[a]--;
        p[b] = a;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());
        for (int j = 1; j <= t; j++) {
            System.out.println("Scenario " + j + ":");
            int n = Integer.parseInt(br.readLine());
            int k = Integer.parseInt(br.readLine());
            Arrays.fill(p,0, n + 1, -1);
            for (int i = 0; i < k; i++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                union(a,b);
            }

            int m = Integer.parseInt(br.readLine());
            for (int i = 0; i < m; i++){
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                if (find(u) == find(v)) {
                    System.out.println(1);
                } else {
                    System.out.println(0);
                }
            }
            if (j != t)
                System.out.println();
        }
    }
}
