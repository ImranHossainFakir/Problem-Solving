import java.util.Scanner;
 
public class BWOWFactor {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
 
        outer : while (t-- > 0) {
            int n, i, j;
            boolean flag = true;
            n = in.nextInt();
            String[] numbers = new String[n];
            for (i = 0; i < n; i++) numbers[i] = in.next();
 
            for (i = 0; i < n-1; i++) {
                for (j = 0; j < n - 1; j++) {
                    if (numbers[i].charAt(j) == '1') {
                        if (numbers[i + 1].charAt(j) == '1' || numbers[i].charAt(j + 1) == '1') continue;
                        System.out.println("NO");
                        continue outer;
                    }
                }
            }
            System.out.println("YES");
        }
    }
}