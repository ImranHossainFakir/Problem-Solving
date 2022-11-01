import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
            int n, m, i, j, pos;
            n = in.nextInt();
            m = in.nextInt();
            pos = 0;
            int[][] numbers = new int[n][m];
            long[][] sortingArr = new long[n][m];
 
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    int num = in.nextInt();
                    numbers[i][j] = num;
                    sortingArr[i][j] = num;
                }
            }
            while (pos < m) {
                int a, b;
                a = 0;
                b = 0;
                long min = sortingArr[0][0];
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        if (sortingArr[i][j] < min) {
                            min = sortingArr[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
                numbers[a][b] = numbers[a][pos];
                numbers[a][pos] = (int)min;
                sortingArr[a][b] = sortingArr[a][pos];
                sortingArr[a][pos++] = 1000000001;
            }
 
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) System.out.print(numbers[i][j] + " ");
                System.out.println();
            }
        }
    }
}