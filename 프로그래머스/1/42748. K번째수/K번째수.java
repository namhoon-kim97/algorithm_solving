import java.util.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        List<Integer> tempList = new ArrayList<>();
        
        for (int i = 0; i < commands.length; i++){
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            int st = commands[i][0];
            int en = commands[i][1];
            int idx = commands[i][2];
            for (int j = st - 1; j < en; j++)
                pq.add(array[j]);
            int cnt = 1;
            while(cnt++ != idx)
                pq.poll();
            tempList.add((int)pq.poll());
        }
        int[] result = new int[tempList.size()];
        for (int i = 0; i < tempList.size(); i++) {
            result[i] = tempList.get(i);
        }
        return result;
    }
}