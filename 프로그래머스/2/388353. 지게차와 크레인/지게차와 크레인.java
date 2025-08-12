import java.util.*;
class Solution {
    char[][] board = new char[52][52];
    int n,m;
    int[] dx = new int[]{1,0,-1,0};
    int[] dy = new int[]{0,1,0,-1};
    
    void removeBoundary(char target){
        boolean[][] vis = new boolean[n+2][m+2];
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0,0});
        vis[0][0] = true;
        while(!q.isEmpty()){
            int[] cur = q.poll();
            for (int i = 0; i < 4; i++){
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                if (nx < 0 || ny < 0 || nx >= n + 2 || ny >= m + 2) continue;
                if (vis[nx][ny]) continue;
                if (board[nx][ny] == target){
                    board[nx][ny] = '1';
                    vis[nx][ny] = true;
                    continue;
                }
                if (board[nx][ny] != '1') continue;
                vis[nx][ny] = true;
                q.add(new int[]{nx,ny});
            }
        }
    }
    
    void removeAll(char target){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (board[i][j] == target)
                    board[i][j] = '1';
            }
        }
    }
    
    public int solution(String[] storage, String[] requests) {
        n = storage.length;
        m = storage[0].length();
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= m + 1; j++){
                board[i][j] = '1';
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                board[i][j] = storage[i-1].charAt(j-1);
            }
        }
        
        for (String request : requests){
            if (request.length() == 1){
                // 바깥에 있는 알파벳만 제거
                removeBoundary(request.charAt(0));
            } else {
                // 전체 알파벳 제거
                removeAll(request.charAt(0));
            }
        }
        
        int answer = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (board[i][j] != '1')
                    answer++;
            }
        }
        return answer;
    }
}