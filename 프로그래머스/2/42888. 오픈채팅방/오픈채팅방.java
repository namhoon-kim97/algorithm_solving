import java.util.*;
class Solution {
    public String[] solution(String[] record) {
        HashMap<String, String> name = new HashMap<>();
        List<String> ret = new ArrayList<>();
        for (String a : record){
            String[] cur = a.split(" ");
            if (!cur[0].equals("Leave")){
                name.put(cur[1], cur[2]);
            }
        }
        
        for (String a : record){
            String[] cur = a.split(" ");
            if (cur[0].equals("Enter")){
                ret.add(new String(name.get(cur[1]) + "님이 들어왔습니다."));
            } else if (cur[0].equals("Leave")){
                ret.add(new String(name.get(cur[1]) + "님이 나갔습니다."));
            }
        }
        
        return ret.toArray(new String[ret.size()]);
    }
}