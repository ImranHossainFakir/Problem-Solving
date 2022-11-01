import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
 
        while (t-- > 0) {
            int a1, a2;
            long n, tem;
            n = tem = input.nextLong();
            a1 = a2 = 0;
            while (tem > 0) {
                if (tem % 10 == 0) break;
                tem /= 10;
                a2++;
            }
            tem /= 10;
            while (tem > 0) {
                if (((tem%10) * 10) % 25 == 0) break;
                a2++;
                tem /= 10;
            }
            while (n > 0) {
                if (n % 10 == 5) break;
                n /= 10;
                a1++;
            }
 
            n /= 10;
 
            while (n > 0) {
                if ((((n % 10) * 10) + 5) % 25 == 0) break;
                a1++;
                n /= 10;
            }
 
            System.out.println(Math.min(a1, a2));
        }
    }
}