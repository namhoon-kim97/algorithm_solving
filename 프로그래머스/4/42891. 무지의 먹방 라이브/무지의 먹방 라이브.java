import java.util.*;
class Solution {
    public int solution(int[] food_times, long k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> {
            if (a[0] != b[0]) 
                return Integer.compare(a[0],b[0]);
            return Integer.compare(a[1],b[1]);
            }); // food, idx
        for (int i = 0; i < food_times.length; i++){
            pq.add(new int[]{food_times[i], i + 1});
        }
        
        long last = 0;
        while (!pq.isEmpty()){
            long cur = pq.peek()[0];
            long diff = (cur - last) * (long) pq.size();
            if (k >= diff){
                k -= diff;
                last = cur;
                while (!pq.isEmpty() && pq.peek()[0] == cur)
                    pq.poll();
            } else {
                int size = pq.size();
                List<int[]> remain = new ArrayList<>(pq);
                remain.sort(Comparator.comparingInt(a -> a[1]));
                int idx = (int)(k % size);
                return remain.get(idx)[1];
            }
        }
        
        return -1;
    }
}