import java.util.*;
import java.io.*;

public class Main {
    static int[] A = new int[1001];
    static List<Integer> ASum = new ArrayList<>();
    static int[] B = new int[1001];
    static List<Integer> BSum = new ArrayList<>();
    static HashMap<Integer,Integer> hm = new HashMap<>();

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i  = 0 ; i < n; i++)
            A[i] = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++){
            int sum = 0;
            for (int j = i; j < n; j++){
                sum += A[j];
                ASum.add(sum);
                hm.put(sum, hm.getOrDefault(sum, 0) + 1);
            }
        }

        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i  = 0 ; i < m; i++)
            B[i] = Integer.parseInt(st.nextToken());
        for (int i = 0; i < m; i++){
            int sum = 0;
            for (int j = i; j < m; j++){
                sum += B[j];
                BSum.add(sum);
            }
        }

        long res = 0;
        for (Integer b: BSum){
            if (hm.containsKey(t-b)){
                res += (long)hm.get(t - b);
            }
        }
        System.out.println(res);
    }
}