import java.util.*;
class Solution {
    
    String tobinary(int num, int n){
        StringBuilder sb = new StringBuilder();
        while (num > 0){
            sb.append(num % 2);
            num /= 2;
        }
        if (sb.length() != n){
            while (sb.length() != n)
                sb.append('0');
        }
        return sb.reverse().toString();
    }
    
    public String[] solution(int n, int[] arr1, int[] arr2) {
        List<Integer> nums = new ArrayList<>();
        for (int i = 0; i < n; i++){
            nums.add(arr1[i] | arr2[i]);
        }
        List<String> ret = new ArrayList<>();
        for (int i = 0; i < n; i++){
            int cur = nums.get(i);
            String binary = tobinary(cur,n);
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < binary.length(); j++){
                if (binary.charAt(j) == '1')
                    sb.append('#');
                else sb.append(' ');
            }
            ret.add(sb.toString());
        }
        return ret.toArray(new String[ret.size()]);
    }
}