import java.util.*;
class Solution {
    public boolean solution(int[][] key, int[][] lock) {
        int M = key.length;
        int N = lock.length;
        
        int pad = M - 1;
        int SIZE = N + 2 * pad;
        int[][] board = new int[SIZE][SIZE];
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                board[i + pad][j + pad] = lock[i][j];
        
        int[][] curKey = key;
        for (int r = 0; r < 4; r++) {
              for (int x = 0; x <= SIZE - M; x++) {
                for (int y = 0; y <= SIZE - M; y++){
                    apply(board, curKey, x, y, +1);

                    if (isUnlocked(board, pad, N)) {
                        return true;
                    }

                    apply(board, curKey, x, y, -1);
                }
              }
            curKey = rotate90(curKey);
        }
        return false;
    }
    
    private void apply(int[][] board, int[][] key, int x, int y, int sign) {
        int M = key.length;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                board[x + i][y + j] += key[i][j] * sign;
            }
        }
    }
    private boolean isUnlocked(int[][] board, int pad, int N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[pad + i][pad + j] != 1) return false;
            }
        }
        return true;
    }
    private int[][] rotate90(int[][] prev){
        int[][] cur = new int[prev.length][];
        for (int i = 0; i < prev.length; i++) {
            cur[i] = Arrays.copyOf(prev[i], prev[i].length);
        }
        int n = prev.length;
        int m = prev[0].length;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cur[i][j] = prev[m - j - 1][i];
            }
        }
        return cur;
    }
}