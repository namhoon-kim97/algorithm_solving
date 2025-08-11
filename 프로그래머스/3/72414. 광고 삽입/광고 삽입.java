import java.util.*;
class Solution {
    int[] diff = new int[360001];
    long[] viewers = new long[360001];
    long[] sum = new long[360001];

    int timeToInt(String input){
        String[] a = input.split(":");
        int carry = 1;
        int ret = 0;
        for (int i = a.length - 1; i >= 0; i--){
            ret += (Integer.parseInt(a[i]) * carry);
            carry *= 60;
        }
        return ret;
    }
    
     String intToTime(int t) {
        int h = t / 3600;
        int m = (t % 3600) / 60;
        int s = t % 60;
        return String.format("%02d:%02d:%02d", h, m, s);
    }
    
    public String solution(String play_time, String adv_time, String[] logs) {
        int playT = timeToInt(play_time);
        int advT = timeToInt(adv_time);
        if (advT >= playT) return "00:00:00";
        
        for (String log : logs){
            String[] temp = log.split("-"); // temp[0] 시작, temp[1] 끝
            int st = timeToInt(temp[0]);
            int en = timeToInt(temp[1]);
            diff[st] += 1;
            diff[en] -= 1;
        }
        viewers[0] = diff[0];
        for (int i = 1; i <= playT; i++){
            viewers[i] = viewers[i - 1] + diff[i];
        }
        
        sum[0] = viewers[0];
        for (int i = 1; i <= playT; i++) {
            sum[i + 1] = sum[i] + viewers[i];
        }
        
       
        long maxSum = -1;
        int bestStart = 0;

        for (int i = 0; i + advT <= playT; i++) {
            long cur = sum[i + advT] - sum[i];
            if (cur > maxSum) {
                maxSum = cur;
                bestStart = i;
            }
        }
        return intToTime(bestStart);
    }
}