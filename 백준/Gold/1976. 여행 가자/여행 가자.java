import static java.lang.System.exit;

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
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        Arrays.fill(p, 0, n + 1,-1);
        StringTokenizer st;
        for (int i = 1; i <= n; i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++){
                int cur = Integer.parseInt(st.nextToken());
                if (cur == 1){
                    union(i,j);
                }
            }
        }
        st = new StringTokenizer(br.readLine());
        int root = 0;
        int pre = 0;
        for (int i = 0; i < m; i++){
            int cur = Integer.parseInt(st.nextToken());
            root = find(cur);
            if (i != 0 && root != pre){
                System.out.println("NO");
                exit(0);
            }
            pre = root;
        }
        System.out.println("YES");
    }
}
