import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] arr = new int[21];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        // 전체 조합
        int res = 0;
        for (int i = 1; i < (1 << n); i++){
            // 현재 선택 조합
            int cur = 0;
            for (int j = 0; j < n; j++){
                if ((i & (1 << j)) != 0){
                    cur += (arr[j]);
                }
            }
            if (cur == s) res++;
        }
        System.out.println(res);
    }


}
