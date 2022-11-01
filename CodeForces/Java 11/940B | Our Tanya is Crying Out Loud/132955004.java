import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        long n, k, A, B, a, b, cost;
        n = input.nextInt();
        k = input.nextInt();
        A = input.nextInt();
        B = input.nextInt();
        cost = 0;
 
        while (n > 1) {
            if (k == 1) {
                cost = (n-1) * A;
                break;
            }
            if (n < k) {
                cost += (n - 1) * A;
                break;
            }
            a = (n % k) * A + B;
            b = (n - n / k) * A;
            cost += Math.min(a, b);
            n /= k;
        }
 
        System.out.println(cost);
    }
}