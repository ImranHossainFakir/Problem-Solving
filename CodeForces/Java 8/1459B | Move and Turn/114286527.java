import java.util.Scanner;
 
public class BWOWFactor {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n;
        n = in.nextInt();
        if (n % 2 == 0) {
            System.out.println((int)Math.pow(n/2+1, 2));
        } else {
            n = (n+2)/2;
            System.out.println(n * (n+1) * 2);
        }
    }
}