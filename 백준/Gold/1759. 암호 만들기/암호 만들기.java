import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {
    static char[] arr = new char[16];
    static boolean[] vis = new boolean[16];
    static List<Character> temp = new ArrayList<>();
    static String v = "aeiou";

    public static void dfs(int cnt, int limit, int c, int idx){
        if (cnt == limit){
           long vCnt = temp.stream()
                           .filter(ch -> v.indexOf(ch) >= 0)
                                   .count();
           long cCnt = temp.stream()
                           .filter(ch -> v.indexOf(ch) == -1)
                                   .count();
           if (vCnt >= 1 && cCnt >= 2)
               System.out.println(temp.stream()
                           .map(String::valueOf)
                           .collect(Collectors.joining()));
        }
        for (int i = idx; i < c; i++){
            if (vis[i]) continue;
            temp.add(arr[i]);
            vis[i] = true;
            dfs(cnt + 1, limit, c, i);
            temp.remove(temp.size() - 1);
            vis[i] = false;
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int l = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < c; i++){
            arr[i] = st.nextToken().charAt(0);
        }
        Arrays.sort(arr,0,c);

        dfs(0,l,c,0);
    }
}