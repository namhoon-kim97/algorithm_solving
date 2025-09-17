import java.util.*;
class Solution {
    public int[] solution(int N, int[] stages) {
        List<int[]> ret = new ArrayList<>();
        Arrays.sort(stages);
        int before = 0;
        for (int i = 1; i <= N; i++){
            int j = before;
            while (j < stages.length && i >= stages[j]) j++;

            int fail  = j - before;     
            int reach = stages.length - before; 

            if (reach == 0) 
                ret.add(new int[]{0, 1, i}); 
            else            
                ret.add(new int[]{fail, reach, i});
            
            before = j;
        }
        
        ret.sort((a, b) -> {
            long lhs = (long)a[0] * b[1];
            long rhs = (long)b[0] * a[1];
            if (lhs != rhs) return Long.compare(rhs, lhs);
            return Integer.compare(a[2], b[2]);
        });
        
        List<Integer> res = new ArrayList<>();
        for (int[] a : ret){
            res.add(a[2]);
        }
        
        return res.stream()
            .mapToInt(Integer::intValue)
            .toArray();
    }
}