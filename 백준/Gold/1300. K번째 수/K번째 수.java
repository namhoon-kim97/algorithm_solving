import com.sun.source.tree.Tree;
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
    static int n,k;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());

        int en = k;
        int st = 1;
        int ans = 0;
        while (st <= en){
            int mid = (en + st) / 2;
            int cnt = 0;
            for (int i = 1; i <= n; i++){
                cnt += Math.min(n, mid / i);
            }
            if (cnt >= k){
                 ans = mid;
                 en = mid - 1;
            } else st = mid + 1;
        }
        System.out.println(ans);
    }
}
