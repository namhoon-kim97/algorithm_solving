import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++){
            String input = br.readLine();
            if (sb.length() == 0)
                sb.append(input);
            else
                for (int j = 0; j < input.length(); j++){
                    if (input.charAt(j) != sb.charAt(j)) sb.setCharAt(j, '?');
                }
        }
        System.out.println(sb.toString());
    }
}
