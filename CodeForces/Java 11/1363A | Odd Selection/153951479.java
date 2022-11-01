import java.io.*;
import java.math.*;
import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
 
        while (t-- > 0) {
            int n, x, odd, even, a;
            n = input.nextInt();
            a = x = input.nextInt();
            odd = even = 0;
 
            for (int i = 0; i < n; i++) {
                if (input.nextInt() % 2 == 0) even++;
                else odd++;
            }
 
            if (odd < 1) {
                System.out.println("NO");
                continue;
            }
 
            odd--;
            odd = (odd/2)*2;
            x--;
 
            if (even-x > -1) {
                System.out.println("YES");
                continue;
            }
 
            x-=even;
 
            if (x % 2 != 0) x++;
 
            if (x <= odd && a != x) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}
 