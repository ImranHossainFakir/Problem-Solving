import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n, i, j;
        n = input.nextInt();
        long[][] higths = new long[2][n];
 
        for (i = 0; i < 2; i++) {
            for (j = 0; j < n; j++) higths[i][j] = input.nextInt();
        }
 
        for (i = 1; i < n; i++) {
            for (j = 0; j < 2; j++) {
                long tem = higths[j][i];
                for (int k = i-1, l = 0; k >= 0 && l < 2; k--, l++) higths[j][i] = Math.max(higths[j][i], tem+higths[(j+1)%2][k]);
            }
        }
        System.out.println(Math.max(higths[0][n-1], higths[1][n-1]));
    }
}