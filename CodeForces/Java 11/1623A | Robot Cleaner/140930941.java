import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
 
        while (t-- > 0) {
            int n, m, ra, rb, rc, rd;
            n = input.nextInt();
            m = input.nextInt();
            ra = input.nextInt();
            rb = input.nextInt();
            rc = input.nextInt();
            rd = input.nextInt();
 
            if (ra > rc) ra = (n-ra) + (n-rc);
            else ra = rc-ra;
 
            if (rb > rd) rb = (m-rb) + (m-rd);
            else rb = rd-rb;
            System.out.println(Math.min(ra, rb));
        }
    }
}