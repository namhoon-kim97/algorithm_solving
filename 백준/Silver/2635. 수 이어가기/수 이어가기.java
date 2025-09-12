import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(br.readLine());

        int first = n;
        int num = 0;
        List<Integer> ret = new ArrayList<>();
        ret.add(n);
        for (int i = n ; i > 0; i--){
            List<Integer> res = new ArrayList<>();
            first = n;
            int second = i;
            while (first >= 0){
                if (first < second) break;
                res.add(first - second);
                int temp = second;
                second = first - second;
                first = temp;
            }

            if (num < res.size()){
                num = res.size();
                ret.clear();
                ret.add(n);
                ret.add(i);
                ret.addAll(res);
            }
        }

        System.out.println(ret.size());
        for (Integer a : ret) {
            System.out.print(a + " ");
        }
    }
}
