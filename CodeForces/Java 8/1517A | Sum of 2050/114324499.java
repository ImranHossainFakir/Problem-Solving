import java.util.Scanner;
 
public class BWOWFactor {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
 
        while (t-- > 0) {
            long n, sum;
            sum = 0;
            n = in.nextLong();
            if (n % 2050 != 0) {
                System.out.println(-1);
                continue;
            }
            n /= 2050;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
            System.out.println(sum);
        }
    }
}