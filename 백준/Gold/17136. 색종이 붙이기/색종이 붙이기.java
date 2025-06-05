import com.sun.source.tree.Tree;
import java.io.*;
import java.util.*;

public class Main {
    static int[][] board = new int[11][11];
    static int INF = Integer.MAX_VALUE - 1000000;
    static int ret = INF;
    static Map<Integer, Integer> mp = new HashMap<>();

    static boolean check(int x, int y, int off){
        if (x + off > 10 || y + off > 10) return false;
        for (int i = x; i < x + off; i++){
            for (int j = y; j < y + off; j++)
                 if (board[i][j] == 0) return false;
        }
        return true;
    }

    static void draw(int x, int y, int off,int v){
        for (int i = x; i < x + off; i++){
            for (int j = y; j < y + off; j++)
                board[i][j] = v;
        }
    }

    static void dfs(int x, int y, int cnt){
        if (cnt >= ret) return;
        if (y == 10){
            dfs(x + 1, 0, cnt);
            return;
        }
        if (x == 10){
            ret = Math.min(ret, cnt);
            return;
        }
        if (board[x][y] == 0){
            dfs(x, y + 1, cnt);
            return;
        }
        for (int _size = 5; _size >= 1; _size--){
            if (mp.getOrDefault(_size, -1) == 5) continue;
            if (check(x,y,_size)){
                mp.put(_size, mp.getOrDefault(_size,0) + 1);
                draw(x,y,_size,0);
                dfs(x,y + _size,cnt+1);
                draw(x,y,_size,1);
                mp.put(_size, mp.getOrDefault(_size,0) - 1);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        for (int i = 0; i < 10; i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 10; j++)
                board[i][j] = Integer.parseInt(st.nextToken());
        }
        dfs(0,0,0);
        if (ret != INF) {
            System.out.println(ret);
        } else {
            System.out.println(-1);
        }

    }
}
