import java.util.*;
class Solution {
    public int solution(String[] friends, String[] gifts) {
        int n = friends.length;
        Map<String, Integer> friendsIdx = new HashMap<>();
        int[][] toGifts = new int[n+1][n+1];
        int[] giveCnt = new int[n+1];
        int[] receiveCnt = new int[n+1];
        int[] giftIdx = new int[n+1];
        int idx = 0;
        for (String a : friends){
            friendsIdx.put(a, idx);
            idx++;
        }
        
        for (String a : gifts){
            String[] temp = a.split(" ");
            toGifts[friendsIdx.get(temp[0])][friendsIdx.get(temp[1])]++;
            giveCnt[friendsIdx.get(temp[0])]++;
            receiveCnt[friendsIdx.get(temp[1])]++;
        }
        
        for (String a : friends){
            int cur = friendsIdx.get(a);
            giftIdx[cur] = giveCnt[cur] - receiveCnt[cur];
        }
        
        int[] res = new int[n+1];
        for (int i = 0; i < n; i++){
            int a = friendsIdx.get(friends[i]);
            for (int j = i + 1; j < n; j++){
                int b = friendsIdx.get(friends[j]);
                if (toGifts[a][b] < toGifts[b][a]) res[b]++;
                else if (toGifts[a][b] > toGifts[b][a]) res[a]++;
                else {
                    if (giftIdx[a] < giftIdx[b]) res[b]++;
                    else if (giftIdx[a] > giftIdx[b]) res[a]++;
                    else continue;
                }
            }
        }
        
        int answer = 0;
        for (int i = 0; i < n; i++)
            answer = Math.max(answer, res[i]);
        return answer;
    }
}