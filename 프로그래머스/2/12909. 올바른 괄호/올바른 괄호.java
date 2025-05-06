import java.util.*;
class Solution {
    boolean solution(String s) {
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < s.length(); i++){
            if (s.charAt(i) == '('){
                st.push(s.charAt(i) - '0');
            } else{
                if (st.empty()) return false;
                st.pop();
            }
        }
        if (!st.empty()) return false;
            

        return true;
    }
}