import java.util.*;
class Solution {
    boolean isRight(String s){
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); i++){
            if (s.charAt(i) == ')'){
                if (st.isEmpty()) return false;
                st.pop();
            } else {
                st.push(s.charAt(i));
            }
        }
        return st.isEmpty();
    }
    
    String dfs(String cur){
        if (cur.equals("")) return cur;
        int cnt1 = 0;
        int cnt2 = 0;
        int idx = 0;
        for (int i = 0; i < cur.length(); i++){
            if (cur.charAt(i) == '(') cnt1++;
            if (cur.charAt(i) == ')') cnt2++;
            if (cnt1 == cnt2) {
                idx = i;break;
            }
        }
        String left = cur.substring(0,idx+1);
        String right = (idx + 1 < cur.length()) ? cur.substring(idx + 1) : "";
        if (isRight(left))
            return left + dfs(right);
        else{
            StringBuilder sb = new StringBuilder();
            for (int i = 1; i < left.length() - 1; i++){
                char temp = (left.charAt(i) == '(') ? ')' : '(';
                sb.append(temp);
            }
            return "(" + dfs(right) + ")" + sb.toString();
        }
    }
    
    public String solution(String p) {
        return dfs(p);
    }
}