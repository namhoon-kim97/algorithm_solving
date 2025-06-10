import com.sun.source.tree.Tree;
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
    static int n,c;
    static int[] arr = new int[31];

    static void dfs(int idx, long sum, List<Long> v, int _n){
        if (sum > c) return;
        if (idx > _n) {
            v.add(sum);
            return;
        }
        dfs(idx + 1, sum + arr[idx],v, _n);
        dfs(idx + 1, sum,v, _n);
    }

    static int upperBound(List<Long> v, Long target){
        int st = 0;
        int en = v.size();
        while(st < en){
            int mid = (st + en) / 2;
            if (v.get(mid) <= target)
                st = mid + 1;
            else
                en = mid;
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
        List<Long> v1 = new ArrayList<>();
        List<Long> v2 = new ArrayList<>();
        dfs(0, 0, v1, n / 2 - 1);
        dfs(n/2, 0, v2, n-1);
        Collections.sort(v1);
        Collections.sort(v2);

        int res = 0;
        for (Long a: v1){
           if (c - a >= 0) res += upperBound(v2, c- a);
        }
        System.out.println(res);
    }
}
