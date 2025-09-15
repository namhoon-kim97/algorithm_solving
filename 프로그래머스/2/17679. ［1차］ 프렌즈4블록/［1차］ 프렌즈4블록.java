class Solution {
    public int solution(int m, int n, String[] board) {
        char[][] board2 = new char[m][n];
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                board2[i][j] = board[i].charAt(j);
            }
        }
        boolean flag = false;
        int answer = 0;
        while (!flag){
            flag = true;
            boolean[][] vis = new boolean[m][n];
            for (int i = 0; i < m - 1; i++){
                for (int j = 0; j < n - 1; j++){
                    char c = board2[i][j];
                    if (c == '1') continue;
                    if (c == board2[i][j+1]
                        && c == board2[i+1][j]
                        && c == board2[i+1][j+1]) {
                        flag = false;
                        vis[i][j] = vis[i][j+1] = vis[i+1][j] = vis[i+1][j+1] = true;
                    }
                }
            }
            
            int removed = 0;
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    if (vis[i][j]) {
                        if (board2[i][j] != '1') removed++;
                        board2[i][j] = '1';
                    }
                }
            }
            answer += removed;
            if (removed == 0) break;
            
            
            for (int j = 0; j < n; j++){
                int write = m - 1;
                for (int i = m - 1; i >= 0; i--){
                    if (board2[i][j] != '1'){
                        board2[write][j] = board2[i][j];
                        if (write != i) board2[i][j] = '1';
                        write--;
                    }
                }
            }
        }
        return answer;
    }
}