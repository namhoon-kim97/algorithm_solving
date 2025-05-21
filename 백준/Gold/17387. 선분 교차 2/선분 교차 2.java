import java.util.*;
import java.io.*;

public class Main {
    static List<Dot> dots = new ArrayList<>();
    static class Dot{
        long x,y;
        public Dot(long x, long y){
            this.x = x;
            this.y = y;
        }
    }
    public static int ccw(Dot a, Dot b, Dot c){
        long s = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
        return Long.compare(s, 0);
    }

    public static boolean onSeg(Dot a, Dot b, Dot c){
        return Math.min(a.x,b.x) <= c.x && Math.max(a.x,b.x) >= c.x
                && Math.min(a.y,b.y) <= c.y && Math.max(a.y, b.y) >= c.y;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int j = 0 ; j < 2 ; j++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 2; i++) {
                long x = Long.parseLong(st.nextToken());
                long y = Long.parseLong(st.nextToken());
                dots.add(new Dot(x, y));

            }
        }


        int ab_c = ccw(dots.get(0), dots.get(1), dots.get(2));
        int ab_d = ccw(dots.get(0), dots.get(1), dots.get(3));
        int cd_a = ccw(dots.get(2), dots.get(3), dots.get(0));
        int cd_b = ccw(dots.get(2), dots.get(3), dots.get(1));

        if (ab_c * ab_d < 0 && cd_a * cd_b < 0) System.out.println(1);
        else if (ab_c == 0 && onSeg(dots.get(0), dots.get(1), dots.get(2))) System.out.println(1);
        else if (ab_d == 0 && onSeg(dots.get(0), dots.get(1), dots.get(3))) System.out.println(1);
        else if (cd_a == 0 && onSeg(dots.get(2), dots.get(3), dots.get(0))) System.out.println(1);
        else if (cd_b == 0 && onSeg(dots.get(2), dots.get(3), dots.get(1))) System.out.println(1);
        else {
            System.out.println(0);
        }
    }
}