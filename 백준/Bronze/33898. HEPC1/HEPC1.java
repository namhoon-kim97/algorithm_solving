import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //StringTokenizer st = new StringTokenizer(br.readLine());
        String a = br.readLine();
        String b = br.readLine();

        String t = a + b;
        if (t.equals("HECP") || t.equals("HCEP") || t.equals("EHPC") || t.equals("CHPE")){
            System.out.println("YES");
            return;
        }
        t = b + a;
        if (t.equals("HECP") || t.equals("HCEP") || t.equals("EHPC") || t.equals("CHPE")){
            System.out.println("YES");
            return;
        }
        System.out.println("NO");
    }
}
