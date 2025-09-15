import java.util.*;
class Solution {
    public String solution(int n, int t, int m, String[] timetable) {
        // 현재 시간 이하로 온것들만 쳐냄.
        // t간격 n번 뒤로 m만큼 쳐내면서 보냄.
        // 마지막 전에서 껴넣음.
        // 기준 시간 09:00 -> 540분
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (String a : timetable){
            String[] temp = a.split(":");
            int hour = Integer.parseInt(temp[0]);
            int minute = Integer.parseInt(temp[1]);
            pq.add(minute + (hour * 60));
        }
        
        int cur = 540;
        int ans = 540;
        int last = 0;
        
        for (int i = 0; i < n; i++){
            ans = cur;
            int boarded = 0;
            for (int j = 0; j < m; j++){
                if (!pq.isEmpty() && pq.peek() <= cur){
                    last = pq.poll();  // 마지막으로 탄 사람 시간 갱신
                    boarded++;
                } else {
                    break;             // 더 이상 탈 사람 없으면 종료
                }
            }
            if (i == n - 1){
                if (boarded == m){
                    ans = last - 1;
                }
            }
            
            cur += t;
        }
        
        System.out.println(ans);
        return String.format("%02d:%02d", ans / 60 , ans % 60);
    }
}