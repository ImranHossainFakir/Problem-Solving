import java.io.*;
import java.math.*;
import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
 
        while (t-- > 0) {
            int l, r;
            l = input.nextInt();
            r = input.nextInt();
            if (l*2 <= r) System.out.println(l + " " + (2*l));
            else System.out.println("-1 -1");
        }
    }
}
 