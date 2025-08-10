import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Friend {
        String name;
        int cnt;
        public Friend(String name, int cnt){
            this.name = name;
            this.cnt = cnt;
        }

    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        String[] friends = new String[n];
        Map<String, Integer> popularity = new HashMap<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            friends[i] = st.nextToken();
        }

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                String cur = st.nextToken();
                popularity.put(cur, popularity.getOrDefault(cur, 0) + 1);
            }
        }

        PriorityQueue<Friend> pq = new PriorityQueue<>((a, b) -> {
            if (a.cnt != b.cnt) return Integer.compare(b.cnt, a.cnt);
            return a.name.compareTo(b.name);
        });

        for (String name : friends) {
            pq.add(new Friend(name, popularity.getOrDefault(name, 0)));
        }

        while (!pq.isEmpty()) {
            Friend f = pq.poll();
            System.out.println(f.name + " " + f.cnt);
        }
    }
}
