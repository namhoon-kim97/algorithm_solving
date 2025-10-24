import java.util.*;
class Solution {
    public int[] solution(int[][] dice) {
        int n = dice.length;
        int half = n / 2;
        long bestWin = -1;
        int[] bestPick = null;
        for (int i = 0; i < (1 << n); i++){
            if (Integer.bitCount(i) != (n / 2)) continue;
            int[] A = new int[half];
            int[] B = new int[half];
            int ai = 0; 
            int bi = 0;
            for (int j = 0; j < n; j++){
                if ((i & (1 << j)) != 0){
                    A[ai++] = j;
                }else B[bi++] = j;
            }
            // 선택 주사위 보면서 브루트 포스로 점수
            // 최댓값이면 answer 갱신
            List<Integer> sumsA = new ArrayList<>();
            List<Integer> sumsB = new ArrayList<>();
            makeSums(dice, A, 0, 0, sumsA);
            makeSums(dice, B, 0, 0, sumsB);
            
            Collections.sort(sumsB);
            long wins = 0;
            for (int s : sumsA) {
                int cntLess = lowerBound(sumsB, s);
                wins += cntLess;
            }
            
            if (wins > bestWin) {
                bestWin = wins;
                bestPick = A.clone();
            }
        }
        int[] answer = new int[half];
        for (int i = 0; i < half; i++) answer[i] = bestPick[i] + 1;
        return answer;
    }
    void makeSums(int[][] dice, int[] idx, int pos, int cur, List<Integer> out){
        if (pos == idx.length){
            out.add(cur);
            return;
        }
        int d = idx[pos];
        for (int face = 0; face < 6; face++){
            makeSums(dice, idx, pos + 1, cur + dice[d][face], out);
        }
    }
    
    int lowerBound(List<Integer> arr, int x){
        int l = 0; int r = arr.size();
        while (l < r){
            int m = (l + r) >>> 1;
            if (arr.get(m) < x) l = m + 1;
            else r = m;
        }
        return l;
    }
}