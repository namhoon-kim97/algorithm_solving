import java.util.*;
class Solution {
    public String solution(String new_id) {
        String answer = new_id.toLowerCase();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < answer.length(); i++){
            char cur = answer.charAt(i);
            if (Character.isDigit(cur) || Character.isLetter(cur) || cur == '.' || cur == '_' || cur == '-'){
                sb.append(cur);
            }
        }
        int idx;
        while ((idx = sb.indexOf("..")) != -1)
            sb.replace(idx, idx + 2, ".");
        
        if (sb.charAt(0) == '.') sb.deleteCharAt(0);
        if (sb.length() == 0) sb.append('a');
        if (sb.charAt(sb.length() - 1) == '.') sb.deleteCharAt(sb.length() - 1);
        if (sb.length() == 0) sb.append('a');
        if (sb.length() >= 16){
            sb = new StringBuilder(sb.substring(0,15));
            if (sb.charAt(sb.length() - 1) == '.') sb.deleteCharAt(sb.length() - 1);
        }
        while (sb.length() <= 2){
            sb.append(sb.charAt(sb.length() - 1));
        }
        return sb.toString();
    }
}