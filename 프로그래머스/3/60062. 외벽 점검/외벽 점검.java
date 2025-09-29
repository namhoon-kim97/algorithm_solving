import java.util.*;
class Solution {
    private boolean nextPermutation(int[] a){
        int i = a.length - 2;
        while (i >= 0 && a[i] >= a[i+1]) i--;
        if (i < 0) return false;
        int j = a.length - 1;
        while(a[i] >= a[j]) j--;
        int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
        for (int l = i + 1, r = a.length - 1; l < r; l++, r--) {
            tmp = a[l]; a[l] = a[r]; a[r] = tmp;
        }
        return true;
    }
    private int countNeeded(int[] ext, int st, int m, int[] dist){
        int ret = 1;
        int limit = ext[st] + dist[0];
        for (int i = st; i < st+m; i++){
            if (ext[i] > limit) {
                ret++;
                if (ret > dist.length) return Integer.MAX_VALUE;
                limit = ext[i] + dist[ret - 1];
            }
        }
        return ret;
    }
    public int solution(int n, int[] weak, int[] dist) {
        int m = weak.length;
        int[] ext = new int[m * 2];
        for (int i = 0; i < m; i++) {
            ext[i] = weak[i];
            ext[i + m] = weak[i] + n;
        }
        
        Arrays.sort(dist);
        int answer = Integer.MAX_VALUE;
        for (int st = 0; st < m; st++){
            do{
                int needed = countNeeded(ext, st, m, dist);
                if (needed < answer) answer = needed;
                if (answer == 1) return 1;
            } while(nextPermutation(dist));
            Arrays.sort(dist);
        }
        return (answer == Integer.MAX_VALUE) ? -1 : answer;
    }
}