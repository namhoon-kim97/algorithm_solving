import com.sun.source.tree.Tree;
import java.io.*;
import java.util.*;

public class Main {
    static class Point{
        int x,y,dir;
        public Point(int x, int y, int dir){
            this.x = x;
            this.y = y;
            this.dir = dir;
        }
    }
    static int[][] board = new int[15][15];
    static List<Point> status = new ArrayList<>();
    static List<Integer>[][] A = new ArrayList[15][15];
    static int[] dx = new int[]{0,0,-1,1};
    static int[] dy = new int[]{1,-1,0,0};
    static int n,k;

    static void move(int x, int y, int dir, int i){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 2){
            status.get(i).dir ^= 1;
            nx = x + dx[status.get(i).dir];
            ny = y + dy[status.get(i).dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 2)
                return;
        }
        List<Integer> here = A[x][y];
        int idx = here.indexOf(i);
        List<Integer> moving = new ArrayList<>(here.subList(idx, here.size()));
        here.subList(idx, here.size()).clear();
        if (board[nx][ny] == 1) Collections.reverse(moving);
        A[nx][ny].addAll(moving);
        for (int num : moving) {
            status.get(num).x = nx;
            status.get(num).y = ny;
        }
    }

    static boolean isOver(){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (A[i][j].size() >= 4) return true;
        return false;
    }


    static boolean simul(){
        for (int i = 0; i < status.size(); i++){
            Point p = status.get(i);
            move(p.x, p.y, p.dir, i);
            if (isOver()) return true;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                A[i][j] = new ArrayList<>();
            }
        }

        for (int i = 0; i < k; i++){
            st= new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken()) - 1;
            int d = Integer.parseInt(st.nextToken()) - 1;
            A[r][c].add(i);
            status.add(new Point(r,c,d));
        }

        int cnt = 0;
        boolean flag = false;
        while (cnt <= 1000){
            cnt++;
            if (simul()){
                flag = true;
                break;
            }
        }
        if (flag) System.out.println(cnt);
        else System.out.println(-1);
    }
}
