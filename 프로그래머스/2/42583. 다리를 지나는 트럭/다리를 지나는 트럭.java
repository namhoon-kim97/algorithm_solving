import java.util.*;

class Solution {
    class Temp{
        int weight;
        int inTime;
        public Temp(int w, int t){
            this.weight = w;
            this.inTime = t;
        }
    }
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int cnt = 0;
        // 큐에 들어갈 수 있으면 삽입
        // 못들어가면 cnt 증가하면서 팝
        Queue<Temp> q = new LinkedList<>();
        int qSize = 0;
        for (int i = 0; i < truck_weights.length; i++){
            while (!q.isEmpty() && q.size() > bridge_length){
                cnt = q.peek().inTime + bridge_length;
                qSize -= q.peek().weight;
                q.poll();
            }
            while (!q.isEmpty() && cnt - q.peek().inTime  >= bridge_length){
                cnt = q.peek().inTime + bridge_length;
                qSize -= q.peek().weight;
                q.poll();
            }
            if (qSize + truck_weights[i] <= weight){
                cnt++;
                q.add(new Temp(truck_weights[i], cnt));
                qSize += truck_weights[i];
            } else{
                while (qSize + truck_weights[i] > weight){
                    cnt = q.peek().inTime + bridge_length;
                    qSize -= q.peek().weight;
                    q.poll();
                }
                q.add(new Temp(truck_weights[i], cnt));
                qSize += truck_weights[i];
            }
        }
        while (!q.isEmpty()){
            cnt = q.peek().inTime + bridge_length;
            q.poll();
        }
        return cnt;
    }
}