class Solution {
    boolean[] vis = new boolean[21];
    int ret = 0;
    public int sum(int[] numbers){
        int temp = 0;
        for (int i = 0; i < numbers.length; i++)
            temp += numbers[i];
        return temp;
    }
    public void dfs(int[] numbers, int target, int cnt){
        if (sum(numbers) == target){
            ret++;
            // for (int i = 0; i < numbers.length; i++)
            //     System.out.print(numbers[i]);
            // System.out.println();
            return;
        }
        for (int i = cnt; i < numbers.length; i++){
            if (vis[i]) continue;
            numbers[i] *= -1;       
            vis[i] = true;
            dfs(numbers, target, i);
            vis[i] = false;      
            numbers[i] *= -1;
        }
    }
    
    public int solution(int[] numbers, int target) {
        int answer = 0;
        dfs(numbers, target, 0);
        answer = ret;
        return answer;
    }
}