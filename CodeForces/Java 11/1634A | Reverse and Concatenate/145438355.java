import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
 
        while (t-- > 0) {
            int k, n;
            n = input.nextInt();
            k = input.nextInt();
            String str = input.next();
            boolean flag = true;
            for (int i = 0, j = n-1; i <= j; i++, j--) {
                if (str.charAt(i) == str.charAt(j)) continue;
                flag = false;
                break;
            }
 
            if (flag || k == 0) System.out.println(1);
            else System.out.println(2);
        }
    }
 
    static class FastScanner {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer("");
    }
}