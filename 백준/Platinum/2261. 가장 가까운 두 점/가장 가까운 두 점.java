import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Dot{
        int x,y;
        Dot(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    static int dist(Dot a, Dot b){
        int dx = a.x - b.x;
        int dy = a.y - b.y;
        return dx * dx + dy * dy;
    }

    static int brute(List<Dot> v, int l, int r){
        int best = Integer.MAX_VALUE;
        int n = v.size();
        for (int i = l; i < r; i++){
            for (int j = i + 1; j < r; j++){
                best = Math.min(best, dist(v.get(i), v.get(j)));
                if (best == 0) return 0;
            }
        }
        return best;
    }

    static int solve(List<Dot> px, int l, int r){
        int n = r - l;
        if (n <= 3) return brute(px,l,r);

        int mid = (l + r) / 2;
        int midx = px.get(mid).x;

        int d = Math.min(solve(px,l,mid), solve(px,mid,r));
        if (d == 0) return 0;

        List<Dot> strip = new ArrayList<>();
        for (int i = l; i < r; i++){
            int dx = px.get(i).x - midx;
            if (dx * dx <= d) strip.add(px.get(i));
        }

        strip.sort(Comparator.comparingInt(p -> p.y));
        for (int i = 0; i < strip.size(); i++){
            Dot a = strip.get(i);
            for (int j = i + 1; j < strip.size(); j++){
                int dy = strip.get(j).y - a.y;
                if (dy * dy > d) break;
                int dd = dist(a, strip.get(j));
                d = Math.min(d, dd);
                if (d == 0) return 0;
            }
        }
        return d;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        List<Dot> px = new ArrayList<>();
        for (int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            px.add(new Dot(x,y));
        }
        px.sort((a,b) -> {
            if (a.x != b.x) return Integer.compare(a.x,b.x);
            return Integer.compare(a.y,b.y);
        });
        List<Dot> py = new ArrayList<>(px);
        py.sort((a,b) -> {
            if (a.y != b.y) return Integer.compare(a.y,b.y);
            return Integer.compare(a.x,b.x);
        });
        System.out.println(solve(px,0, px.size()));
    }
}
