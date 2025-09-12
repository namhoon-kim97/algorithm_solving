import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(br.readLine());

        int bestSecond = 0;
        int bestLen = 0;
        for (int i = n ; i > 0; i--){
            int first = n;
            int second = i;
            int len = 0;
            while (true){
                if (first < second) break;
                int temp = second;
                second = first - second;
                first = temp;
                len++;
            }

            if (len > bestLen){
                bestLen = len;
                bestSecond = i;
            }
        }

        List<Integer> ret = new ArrayList<>();
        ret.add(n);
        ret.add(bestSecond);
        int first = n;
        int second = bestSecond;
        while (true){
            if (first < second) break;
            int temp = second;
            second = first - second;
            first = temp;
            ret.add(second);
        }

        System.out.println(ret.size());
        for (Integer a : ret) {
            System.out.print(a + " ");
        }
    }
}
