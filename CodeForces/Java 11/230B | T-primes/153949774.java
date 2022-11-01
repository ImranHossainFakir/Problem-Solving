import java.io.*;
import java.math.*;
import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
 
        int t = input.nextInt();
 
        int[] arr = new int[1000001];
        arr[1] = 1;
 
        for (int i = 2; i * i < 1000001; i++) {
            for (int j = 2; j * i < 1000001; j++) arr[i * j] = 1;
        }
 
        while (t-- > 0) {
            double n;
            n = Math.sqrt(input.nextLong());
            if ((int) n == n && arr[(int)n] == 0) System.out.println("YES");
            else System.out.println("NO");
        }
 
    }
}
 