class Solution {
    public int solution(String s) {
        int answer = s.length();
        for (int i = 1; i <= s.length() / 2; i++){
            StringBuilder compressed = new StringBuilder();
            String prev = s.substring(0,i);
            int cnt = 1;
            
            for (int j = i; j <= s.length(); j += i){
                String next = j + i <= s.length() ? s.substring(j, j + i) : s.substring(j);
                if (prev.equals(next)) cnt++;
                else {
                    compressed.append(cnt > 1 ? cnt + prev : prev);
                    prev = next;
                    cnt = 1;
                }
            }
            compressed.append(cnt > 1 ? cnt + prev : prev);
            answer = Math.min(answer, compressed.length());
        }
        return answer;
    }
}