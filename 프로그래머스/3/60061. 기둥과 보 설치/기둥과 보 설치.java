import java.util.*;
class Solution {
    boolean[][] pillar, beam;
    int N;
    
    boolean canPlaceBeam(int x, int y){
        return (y > 0 && pillar[x][y-1]) || (x + 1 <= N && y > 0 && pillar[x+1][y-1]) 
            || (x > 0 && x + 1 <= N && beam[x-1][y] && beam[x+1][y]);
    }
    
    boolean canPlacePillar(int x, int y){
        return y == 0 || (y > 0 && pillar[x][y-1])
            || (x > 0 && beam[x-1][y])
            || beam[x][y];
    }
    
    boolean isValid(){
        for (int x = 0; x <= N; x++){
            for (int y = 0; y <= N; y++){
                if (pillar[x][y] && !canPlacePillar(x,y)) return false;
                if (beam[x][y] && !canPlaceBeam(x,y)) return false;
            }
        }
        return true;
    }
    
    
    public int[][] solution(int n, int[][] build_frame) {
        N = n;
        pillar = new boolean[n+2][n+2];
        beam = new boolean[n+2][n+2];
        for (int[] cmd : build_frame){
            int x = cmd[0], y = cmd[1], a = cmd[2], b = cmd[3];
            if (b == 1){ // 설치
                 if (a == 0) { // 기둥                     
                     if (canPlacePillar(x,y))
                         pillar[x][y] = true;
                 } else{ // 보
                     if (canPlaceBeam(x,y))
                         beam[x][y] = true;
                 }
                
            } else{ // 삭제
                if (a == 0)
                    pillar[x][y] = false;
                else beam[x][y] = false;
                
                if (!isValid()){ // 유효하지 않으면 원복
                    if (a == 0) pillar[x][y] = true;
                    else beam[x][y] = true;
                }
            }
            
        }
        
        List<int[]> res = new ArrayList<>();
        for (int x = 0; x <= n; x++) {
            for (int y = 0; y <= n; y++) {
                if (pillar[x][y]) res.add(new int[]{x, y, 0});
                if (beam[x][y])   res.add(new int[]{x, y, 1});
            }
        }
        
        res.sort((p,q) -> {
            if (p[0] != q[0]) return p[0] - q[0];
            if (p[1] != q[1]) return p[1] - q[1];
            return p[2] - q[2];
        });
        int[][] answer = new int[res.size()][3];
        for (int i = 0; i < res.size(); i++) answer[i] = res.get(i);
        return answer;
    }
}