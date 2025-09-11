import java.util.*;
class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        int i = 0;
        List<Integer> ans = new ArrayList<>();
        while (i + 1 < dartResult.length()){
            if (!Character.isDigit(dartResult.charAt(i))){
                i++;
                continue;
            }
            String temp = "";
            while (Character.isDigit(dartResult.charAt(i))){
                temp += dartResult.charAt(i);
                i++;
            }
            int score = Integer.parseInt(temp);
            char bonus = dartResult.charAt(i);
            int option = 1;
        
            if (bonus == 'D') score = (score * score);
            else if (bonus == 'T') score = (score * score * score);

            if (i + 1 < dartResult.length() && dartResult.charAt(i + 1) == '*'){
                if (ans.size() != 0){
                    ans.set(ans.size() - 1, ans.get(ans.size() - 1) * 2);
                }
                answer += (score * 2);
            }
            else if (i + 1 < dartResult.length() && dartResult.charAt(i + 1) == '#'){
                answer += (score * -1);
            }
            else {
                answer += score;
            }
            ans.add(answer);
            answer = 0;
            i++;
        }
        for (int a: ans)
            answer += a;
        return answer;
    }
}