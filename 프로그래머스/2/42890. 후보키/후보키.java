import java.util.*;
class Solution {
    public int solution(String[][] relation) {
        int n = relation[0].length;
        int m = relation.length;
        List<Integer> candidateKeys = new ArrayList<>();
        for (int i = 1; i < (1 << n); i++){
            Set<String> set = new HashSet<>();
            for (String[] row : relation){
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < n; j++){
                    if ((i & (1 << j)) != 0){
                        sb.append(row[j]);
                    }
                }
                set.add(sb.toString());
            }
            if (set.size() != m) continue;
            
            boolean minimal = true;
            for (int key : candidateKeys) {
                if ((i & key) == key) {
                    minimal = false;
                    break;
                }
            }
            if (!minimal) continue;

            candidateKeys.add(i);
        }
        
        return candidateKeys.size();
    }
}