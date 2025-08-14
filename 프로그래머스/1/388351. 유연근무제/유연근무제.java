class Solution {
    public int solution(int[] schedules, int[][] timelogs, int startday) {
        for (int i = 0; i < schedules.length; i++){
            int m = schedules[i] % 100;
            int h = schedules[i] / 100;
            int nm = (m + 10) % 60;
            int nh = h + ((m + 10) / 60);
            schedules[i] = nh * 100 + nm;
        }
        int answer = 0;
        startday -= 1;
        for (int i = 0; i < timelogs.length; i++){
            boolean flag = true;
            for (int j = 0; j < timelogs[i].length; j++){
                if (6 - startday - 1 == - 1 && j == 6) continue;
                if (j == (6 - startday - 1) || j == (6 - startday)) continue;
                if (schedules[i] < timelogs[i][j]) flag = false;
            }
            if (flag) answer++;
        }
        return answer;
    }
}   