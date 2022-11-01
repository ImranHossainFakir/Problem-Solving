import java.io.*;
import java.util.*;

public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        int n, m;
        n = input.nextInt();
        m = input.nextInt();
        int[][] arr = new int[n][m];

        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) arr[i][j] = input.nextInt();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(arr[j][i] + " ");
            }
            System.out.println();
        }
    }

    static class FastScanner {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer("");
    }
}