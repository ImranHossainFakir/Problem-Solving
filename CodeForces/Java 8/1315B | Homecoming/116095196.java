import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
            int a, b, p, index, len, i;
            a = in.nextInt();
            b = in.nextInt();
            p = in.nextInt();
            String st = in.next();
            len = st.length();
            index = len;
            int[] ab = new int[2];
            ab[0] = a;
            ab[1] = b;
            if (st.charAt(len-1) == st.charAt(len-2)) p -= ab[st.charAt(len-1)-65];
            for (i = len-1; i > 0; i--) {
                if (st.charAt(i) != st.charAt(i-1)) {
                    p -= ab[st.charAt(i-1)-65];
                }
                if (p < 0) break;
                index--;
            }
            System.out.println(index);
        }
    }
}