import com.sun.source.tree.Tree;
import java.awt.Point;
import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[][] board = new int[21][21];

    static int dfs(int x1, int y1, int x2, int y2, int prevDir){
        int gemCount = 0;
        boolean hasDirty = false;
        // 사각형 내 보석과 불순물 확인
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (board[i][j] == 2) gemCount++;
                if (board[i][j] == 1) hasDirty = true;
            }
        }
        if (gemCount == 0) return 0;
        if (gemCount == 1 && !hasDirty) return 1;

        int total = 0;
        // 자르기 시도
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (board[i][j] != 1) continue;

                // 세로 자르기 (이전 방향은 가로였어야 함)
                if (prevDir != 1) {
                    boolean canCut = true;
                    for (int r = x1; r <= x2; r++) {
                        if (board[r][j] == 2) canCut = false;
                    }
                    if (canCut) {
                        total += dfs(x1, y1, x2, j - 1, 1) * dfs(x1, j + 1, x2, y2, 1);
                    }
                }

                // 가로 자르기 (이전 방향은 세로였어야 함)
                if (prevDir != 0) {
                    boolean canCut = true;
                    for (int c = y1; c <= y2; c++) {
                        if (board[i][c] == 2) canCut = false;
                    }
                    if (canCut) {
                        total += dfs(x1, y1, i - 1, y2, 0) * dfs(i + 1, y1, x2, y2, 0);
                    }
                }
            }
        }

        return total;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        for (int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int res = dfs(0, 0, n - 1, n - 1, -1);
        System.out.println(res == 0 ? -1 : res);

    }
}
