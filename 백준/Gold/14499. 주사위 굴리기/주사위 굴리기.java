import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n,m,x,y,k;
    static int[][] board = new int[21][21];
    static int[] dice = new int[7];
    static int[] dx = {-100,0, 0, -1, 1}; // 동, 서, 북, 남
    static int[] dy = {-100,1, -1, 0, 0};

    static void east(){
        int[] temp = new int[7];
        temp[1] = dice[4];
        temp[2] = dice[2];
        temp[3] = dice[1];
        temp[4] = dice[6];
        temp[5] = dice[5];
        temp[6] = dice[3];
        for (int i = 1; i <= 6; i++)
            dice[i] = temp[i];
    }

    static void west(){
        int[] temp = new int[7];
        temp[4] = dice[1];
        temp[2] = dice[2];
        temp[1] = dice[3];
        temp[6] = dice[4];
        temp[5] = dice[5];
        temp[3] = dice[6];
        for (int i = 1; i <= 6; i++)
            dice[i] = temp[i];
    }

    static void north(){
        int[] temp = new int[7];
        temp[1] = dice[5];
        temp[2] = dice[1];
        temp[3] = dice[3];
        temp[4] = dice[4];
        temp[5] = dice[6];
        temp[6] = dice[2];
        for (int i = 1; i <= 6; i++)
            dice[i] = temp[i];
    }

    static void south(){
        int[] temp = new int[7];
        temp[5] = dice[1];
        temp[1] = dice[2];
        temp[3] = dice[3];
        temp[4] = dice[4];
        temp[6] = dice[5];
        temp[2] = dice[6];
        for (int i = 1; i <= 6; i++)
            dice[i] = temp[i];
    }

    static void fillDice(int x, int y){
        if (board[x][y] == 0)
            board[x][y] = dice[6];
        else {
            dice[6] = board[x][y];
            board[x][y] = 0;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < k; i++){
            int d = Integer.parseInt(st.nextToken());
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            x = nx;
            y = ny;
            switch(d){
                case 1:
                    east();
                    fillDice(x,y);
                    break;
                case 2:
                    west();
                    fillDice(x,y);
                    break;
                case 3:
                    north();
                    fillDice(x,y);
                    break;
                case 4:
                    south();
                    fillDice(x,y);
                    break;
            }
            sb.append(dice[1]).append("\n");
        }
        System.out.println(sb);
    }
}
