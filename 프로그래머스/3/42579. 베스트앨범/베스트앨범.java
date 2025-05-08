import java.util.*;
class Solution {
    
    static class Pair {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    
    public int[] solution(String[] genres, int[] plays) {
        List<Integer> temp = new ArrayList<>();
        Map<String, Integer> map = new TreeMap<>(Collections.reverseOrder());
        Map<String, PriorityQueue<Pair>> map2 = new HashMap<>();
        
        for (int i = 0; i < genres.length; i++){
            if (map.containsKey(genres[i]))
                map.put(genres[i], map.get(genres[i]) + plays[i]);
            else map.put(genres[i], plays[i]);
            
            if (map2.containsKey(genres[i]))
                map2.get(genres[i]).add(new Pair(plays[i], i));
            else{
                PriorityQueue<Pair> list = new PriorityQueue<>((a,b) -> Integer.compare(b.first, a.first));
                list.add(new Pair(plays[i], i));
                map2.put(genres[i], list);
            }
        }
        List<Map.Entry<String, Integer>> sortedGenres = new ArrayList<>(map.entrySet());
        sortedGenres.sort((a, b) -> b.getValue().compareTo(a.getValue()));
        for (Map.Entry<String, Integer> entry : sortedGenres){
            String key = entry.getKey();
            Integer value = entry.getValue();
            
            int cnt = 0;
            while (cnt++ < 2)
                if (!map2.get(key).isEmpty())
                    temp.add(map2.get(key).poll().second);
        }
        int[] answer = new int[temp.size()];
        for (int i = 0; i < temp.size(); i++)
            answer[i] = temp.get(i);
        
        
        return answer;
    }
}