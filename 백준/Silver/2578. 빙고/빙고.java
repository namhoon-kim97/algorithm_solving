import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[][] board = new int[26][26];
    static boolean[][] check = new boolean[26][26];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Map<Integer, int[]> map = new HashMap<>();
        StringTokenizer st;
        for (int i = 0; i < 5; i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; j++){
                int temp = Integer.parseInt(st.nextToken());
                board[i][j] = temp;
                map.put(temp, new int[]{i,j});
            }
        }

        int cnt = 0;
        for (int i = 1; i <= 5; i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= 5; j++){
                int cur = Integer.parseInt(st.nextToken());
                int[] idx = map.get(cur);
                int x = idx[0];
                int y = idx[1];

                check[x][y] = true;
                //가로체크
                cnt = row(x, y, cnt);
                //세로체크
                cnt = col(x, y, cnt);
                //대각선체크
                cnt = diagL(x, y, cnt);
                cnt = diagR(x, y, cnt);

                if (cnt >= 3) {
                    //System.out.println("i: " + i + " j : " + j + " cur : " + cur);
                    System.out.println((i - 1) * 5 + j);
                    exit(0);
                }
            }
        }
    }

    private static int col(int x, int y, int cnt) {
        int boxCnt = -1;
        boolean flag = true;
        int tx = x;
        while (tx >= 0){
            if (!check[tx][y]){
                flag = false;
                break;
            }
            tx--;
            boxCnt++;
        }
        tx = x;
        while (tx < 5){
            if (!check[tx][y]){
                flag = false;
                break;
            }
            tx++;
            boxCnt++;
        }
        if (flag && boxCnt == 5) cnt++;
        return cnt;
    }

    private static int row(int x, int y, int cnt) {
        int boxCnt = -1;
        boolean flag = true;
        //가로체크
        int ty = y;
        while (ty >= 0){
            if (!check[x][ty]){
                flag = false;
                break;
            }
            ty--;
            boxCnt++;
        }
        ty = y;
        while (ty < 5){
            if (!check[x][ty]){
                flag = false;
                break;
            }
            ty++;
            boxCnt++;
        }
        if (flag && boxCnt == 5) cnt++;
        return cnt;
    }

    private static int diagL(int x, int y, int cnt) {
        int boxCnt = -1;
        boolean flag = true;
        int tx = x;
        int ty = y;
        while (tx >= 0 && ty >= 0){
            if (!check[tx][ty]){
                flag = false;
                break;
            }
            tx--;
            ty--;
            boxCnt++;
        }
        tx = x;
        ty = y;
        while (tx < 5 && ty < 5){
            if (!check[tx][ty]){
                flag = false;
                break;
            }
            tx++;
            ty++;
            boxCnt++;
        }
        if (flag && boxCnt == 5) cnt++;
        return cnt;
    }
    private static int diagR(int x, int y, int cnt) {
        int boxCnt = -1;
        boolean flag = true;
        int tx = x;
        int ty = y;
        while (tx < 5 && ty >= 0){
            if (!check[tx][ty]){
                flag = false;
                break;
            }
            tx++;
            ty--;
            boxCnt++;
        }
        tx = x;
        ty = y;
        while (tx >= 0 && ty < 5){
            if (!check[tx][ty]){
                flag = false;
                break;
            }
            tx--;
            ty++;
            boxCnt++;
        }
        if (flag && boxCnt == 5) cnt++;
        return cnt;
    }
}
