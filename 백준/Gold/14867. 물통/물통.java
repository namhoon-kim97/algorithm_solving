import com.sun.source.tree.Tree;
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
    static class Pair{
        int x,y;
        public Pair(int x,int y){
            this.x = x;
            this.y = y;
        }
        @Override
        public boolean equals(Object obj){
            if (this == obj) return true;
            if (!(obj instanceof Pair)) return false;
            Pair other = (Pair) obj;
            return x == other.x && y == other.y;
        }

        @Override
        public int hashCode(){
            return Objects.hash(x,y);
        }
    }

    static Queue<Pair> q = new LinkedList<>();
    static Map<Pair, Integer> m = new HashMap<>();

    static void enqueue(int x, int y, Pair from){
        Pair next = new Pair(x,y);
        if (m.containsKey(next)) return;
        m.put(next, m.get(from) + 1);
        q.add(next);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        q.add(new Pair(0,0));
        m.put(new Pair(0,0), 1);
        while (!q.isEmpty()){
            Pair cur = q.poll();
            enqueue(a, cur.y, cur);
            enqueue(cur.x, b, cur);
            enqueue(0, cur.y, cur);
            enqueue(cur.x, 0, cur);
            enqueue(Math.min(cur.x + cur.y, a), Math.max(0, cur.x + cur.y - a), cur);
            enqueue(Math.max(0, cur.x + cur.y - b), Math.min(cur.x + cur.y, b), cur);
        }
        if (m.getOrDefault(new Pair(c, d),0) != 0) {
            System.out.println(m.get(new Pair(c, d)) - 1);
        } else {
            System.out.println(-1);
        }
    }
}
