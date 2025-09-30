import java.util.*;
class Solution {
    List<String> answer = new ArrayList<>();
    void dfs(char[] a, int idx, int need, StringBuilder sb, Map<String, Integer> m){
        if (need == 0){
            String cur = sb.toString();
            if (m.containsKey(cur)){
                m.put(cur, m.get(cur) + 1);
            } else {
                m.put(cur,1);
            }
            return;
        }
        for (int i = idx; i <= a.length - need; i++){
            sb.append(a[i]);
            dfs(a, i+1, need - 1, sb, m);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
    public String[] solution(String[] orders, int[] course) {
        // course개수 조합 돌면서 counting Map<String, Integer>
        // counting max 기억하고 있다가 map꺼내면서 max값이면 push
        // 최소 2가지 이상의 단품요리, 최소 2명 이상의 손님이 주문
        // answer는 알파벳순 정렬
        for (int i = 0; i < orders.length; i++){
            char[] cur = orders[i].toCharArray();
            Arrays.sort(cur);
            orders[i] = new String(cur);
        }
        for (int a: course){
            Map<String, Integer> m = new HashMap<>();
            for (String o : orders){
                if (o.length() < a) continue;
                dfs(o.toCharArray(), 0, a, new StringBuilder(), m);
            }
            
            int max = 0;
            for (int v : m.values()) max = Math.max(max, v);
            if (max < 2) continue;
            
            for (Map.Entry<String,Integer> entry : m.entrySet()){
                if (entry.getValue() == max) answer.add(entry.getKey());
            }
        }
        Collections.sort(answer);
        return answer.toArray(new String[answer.size()]);
    }
}