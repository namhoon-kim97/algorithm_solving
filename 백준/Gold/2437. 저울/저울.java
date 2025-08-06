import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++){
            pq.add(Integer.parseInt(st.nextToken()));
        }

        int sum = 1;
        while (!pq.isEmpty()){
            int cur = pq.poll();
            if (sum < cur) {
                break;
            }
            sum += cur;
        }
        System.out.println(sum);
        // 1 1 2 3 6 7 30
    }
}
