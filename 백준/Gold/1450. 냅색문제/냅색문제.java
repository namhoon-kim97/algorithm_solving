import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n,c;
    static int[] arr = new int[31];

    static void dfs(int st, int en ,int sum, List<Integer> v){
        if (sum > c) return;
        if (st > en){
            v.add(sum);
            return;
        }
        dfs(st + 1, en, sum + arr[st], v);
        dfs(st + 1, en, sum, v);
    }

    static int upperB(int target, List<Integer> v){
        int st = 0;
        int en = v.size();
        while (st < en){
            int mid = (st + en) / 2;
            if (v.get(mid) > target) en = mid;
            else st = mid +  1;
        }
        return st;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        List<Integer> v1 = new ArrayList<>();
        List<Integer> v2 = new ArrayList<>();
        dfs(0, n / 2 - 1, 0, v1);
        dfs(n / 2, n - 1, 0, v2);
        Collections.sort(v1);
        Collections.sort(v2);
        int ans = 0;
        for (int a : v2){
            if (c - a >= 0)
                ans += upperB(c-a, v1);
        }
        System.out.println(ans);
    }
}
