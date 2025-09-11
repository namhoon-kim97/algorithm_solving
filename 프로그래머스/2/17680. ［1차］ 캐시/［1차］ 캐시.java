import java.util.*;
class Solution {
    public int solution(int cacheSize, String[] cities) {
        Map<String, Integer> m = new LinkedHashMap<>(cacheSize, 0.75f, true);
        int answer = 0;
        for (String city : cities){
            city = city.toLowerCase();
            if (m.getOrDefault(city,-1) == -1){
                answer += 5;
                m.put(city, 1);
                if (m.size() > cacheSize){
                    String oldestKey = m.keySet().iterator().next();
                    m.remove(oldestKey);
                }
            } else {
                answer += 1;
            }
        }
        return answer;
    }
}