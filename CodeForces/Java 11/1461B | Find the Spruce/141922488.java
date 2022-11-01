import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
 
        while (t-- > 0) {
            int n, m, i, j, ans;
            n = input.nextInt();
            m = input.nextInt();
            ans = 0;
            int[][] arr = new int[n+1][m+2];
            String[] strings = new String[n];
 
            for (i = 0; i < n; i++) strings[i] = input.next();
 
            for (i = n; i > 0; i--) {
                for (j = 0; j < m; j++) {
                    if (strings[i-1].charAt(j) == '*') {
                        arr[i-1][j+1] = 1 + Math.min(arr[i][j], Math.min(arr[i][j+2], arr[i][j+1]));
                        ans += arr[i-1][j+1];
                    }
                }
            }
            System.out.println(ans);
        }
    }
}