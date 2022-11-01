import java.util.Scanner;
 
public class BWOWFactor {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
 
        outer : while (t-- > 0) {
            int n, k, i, max;
            n = in.nextInt();
            k = in.nextInt();
            max = 0;
            int[] st1 = new int[27];
            int[] st2 = new int[27];
            String str1, str2;
            str1 = in.next();
            str2 = in.next();
 
            for (i = 0; i < n; i++) {
                st1[str1.charAt(i)-97]++;
                st2[str2.charAt(i)-97]++;
            }
 
            max = 26;
            while (max > 0) if (st2[--max] > 0) break;
 
            for (i = 0; i < 26; i++) {
                if (st1[i] < st2[i]) {
                    System.out.println("NO");
                    continue outer;
                }
                int tem;
                st1[i] -= st2[i];
                tem = st1[i] / k * k;
                st1[i] -= tem;
                if (st1[i] != 0) {
                    System.out.println("NO");
                    continue outer;
                }
                st1[i+1] += tem;
            }
            System.out.println("YES");
        }
    }
}