import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        LinkedHashMap<String, Integer> lm = new LinkedHashMap<>(cacheSize, 0.75f, true);
        int res = 0;
        for (String s : cities){
            s = s.toLowerCase();
            if (lm.getOrDefault(s,0) != 0){
                res += 1;
            } else {
                lm.put(s, 1);
                res += 5;
                if (lm.size() > cacheSize){
                    for (Map.Entry<String,Integer> entry : lm.entrySet()){
                        lm.remove(entry.getKey());
                        break;
                    }
                }
            }
        }
        
        return res;
    }
}