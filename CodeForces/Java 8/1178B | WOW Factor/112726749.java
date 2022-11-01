import java.util.Scanner;
 
public class BWOWFactor {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String st = in.next();
        long w, o, ans;
        w = o = ans = 0;
 
        for (int i = 0; i < st.length(); i++) {
            if (st.charAt(i) == 'o') {
                o += w;
            } else if (i < st.length() - 1 && st.charAt(i) == 'v' && st.charAt(i+1) == 'v') {
                w++;
                ans += o;
            }
        }
 
        System.out.println(ans);
    }
}