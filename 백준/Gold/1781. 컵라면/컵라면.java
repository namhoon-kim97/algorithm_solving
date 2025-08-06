import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        for (int i = 0; i < n; i++){
            int a,b;
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            pq.add(new int[]{a,b});
        }

        PriorityQueue<Integer> pq2 = new PriorityQueue<>();
        int res = 0;
        while (!pq.isEmpty()){
            int[] cur = pq.poll();
            res += cur[1];
            pq2.add(cur[1]);
            if (pq2.size() > cur[0]){
                res -= pq2.poll();;
            }
        }
        System.out.println(res);
    }
}
