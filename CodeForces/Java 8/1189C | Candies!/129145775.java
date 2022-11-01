import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n, i, q;
        n = input.nextInt();
        int[] digits = new int[n+2];
 
        for (i = 1; i <= n; i++) {
            digits[i] = input.nextInt();
        }
 
        for (i = n; i > 0; i--) digits[i-1] += digits[i];
        q = input.nextInt();
 
        while (q-- > 0) {
            int l, r;
            l = input.nextInt();
            r = input.nextInt();
            System.out.println((digits[l]-digits[r+1])/10);
        }
    }
}