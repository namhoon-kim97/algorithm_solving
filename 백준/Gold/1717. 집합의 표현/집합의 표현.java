import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] p = new int[1000001];

    static void union(int a, int b){
        a = find(a);
        b = find(b);
        if (a == b) return; // 이미 같은 그룹 패스

        if (p[b] < p[a]){ // b의 랭크가 높으면 swap
            int temp = a;
            a = b;
            b = temp;
        }
        if (p[a] == p[b]) // 랭크가 같으면 a랭크 증가
            p[a]--;
        p[b] = a;
    }

    static int find(int a){
        if (p[a] < 0) return a;
        return find(p[a]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        for (int i = 0; i <= n; i++){
            p[i] = -1;
        }

        for (int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int c = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if (c == 0){
                union(a,b);
            } else {
                if (find(a) == find(b)) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }

    }
}
