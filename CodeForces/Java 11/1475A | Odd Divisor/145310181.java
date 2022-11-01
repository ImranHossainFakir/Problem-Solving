import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
 
        while (t-- > 0) {
            long n = input.nextLong();
            String ans = "NO";
            while (n > 1) {
                if (n % 2 == 1){
                    ans = "YES";
                    break;
                }
                n/=2;
            }
            System.out.println(ans);
        }
    }
 
    static class FastScanner {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer("");
    }
}