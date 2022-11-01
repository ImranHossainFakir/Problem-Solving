import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
 
        while (t-- > 0) {
            int n, i, count, tem;
            long ans = 0;
            count = tem = 0;
            n = input.nextInt();
            String string = input.next();
            int[] digits = new int[10];
 
            for (i = 0; i < n; i++) {
                digits[string.charAt(i)-48]++;
            }
 
            for (i = 1; i < 10; i++) {
                ans += (long) digits[i] * i;
                count += digits[i];
            }
 
            System.out.println(string.charAt(n-1) == 48 ? ans + count : ans + count - 1);
        }
    }
}