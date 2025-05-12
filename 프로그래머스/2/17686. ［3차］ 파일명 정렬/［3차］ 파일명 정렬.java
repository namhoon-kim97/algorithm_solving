import java.util.*;
class Solution {
    class FileInfo{
        String original;
        String head;
        int number;
        public FileInfo(String original) {
            this.original = original;
            parse();
        }
        
        void parse(){
            String lower = original.toLowerCase();
            int idx = 0;
            while (idx < lower.length() && !Character.isDigit(lower.charAt(idx))) {
                idx++;
            }
            head = lower.substring(0, idx);
            int count = 0;
            int idx2 = idx;
            while (idx < lower.length() && Character.isDigit(lower.charAt(idx)) && count < 5) {
                idx++;
                count++;
            }
            number = Integer.parseInt(lower.substring(idx2, idx));
        }
    }
    
    public String[] solution(String[] files) {
        FileInfo[] fi = Arrays.stream(files).map(f -> new FileInfo(f)).toArray(FileInfo[]::new);
        Arrays.sort(fi, (f1,f2) -> {
            int headCompare = f1.head.compareTo(f2.head);
            if (headCompare != 0) return headCompare;
            return Integer.compare(f1.number, f2.number);
        });
        
         String[] answer = Arrays.stream(fi)
            .map(f -> f.original)
            .toArray(String[]::new);
        return answer;
    }
}