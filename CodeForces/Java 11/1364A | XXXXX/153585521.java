import java.io.*;
import java.math.*;
import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
 
        while (t--  > 0) {
            int a, b, l, r, sum;
            a = input.nextInt();
 
            b = input.nextInt();
            sum = 0;
            l = r = -1;
 
            for (int i = 0; i < a; i++) {
                int tem = input.nextInt();
                sum += tem;
 
                if (tem % b == 0) continue;
 
                if (l == -1) l = i;
                r = i;
            }
 
            if (sum % b != 0) System.out.println(a);
            else if (l == -1) System.out.println(-1);
            else System.out.println(a-Math.min(l+1, a-r));
        }
    }
}
 