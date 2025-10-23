import java.util.*;
class Solution {
    
    public int[] solution(int[][] edges) {
        Map<Integer,Integer> um = new HashMap<>();
        int max = 0;
        for (int[] e : edges) {
            max = Math.max(max, Math.max(e[0], e[1]));
            um.put(e[0], 1);
            um.put(e[1], 1);
        }
        int n = max + 1;

        int[] in = new int[n];
        int[] out = new int[n];
        
        for (int[] e: edges){
            in[e[1]]++;
            out[e[0]]++;
        }
        
        int cNode = 0;
        for (int i = 1; i < n; i++) {
            if (in[i] == 0 && out[i] >= 2) 
                cNode = i;
        }
        
        int donut = 0;
        int rod = 0;
        int eight = 0;
        for (int i = 1; i < n; i++) {
            if (um.getOrDefault(i,0) == 0) continue;
            if (i == cNode) continue;
            if (out[i] == 0) rod++;
            if (in[i] >= 2 && out[i] >= 2) eight++;
        }
        donut = out[cNode] - (rod + eight);
        
        int[] answer = {cNode, donut, rod, eight};
        return answer;
    }
}