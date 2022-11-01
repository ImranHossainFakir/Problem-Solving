import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        int n, count;
        n = input.nextInt();
        count = 0;
 
        int[][] arr = new int[n][3];
 
        for (int i = 0; i < n; i++) for (int j =0; j < 3; j++) arr[i][j] = input.nextInt();
 
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < 3; j++) {
                sum += arr[i][j];
            }
            if (sum > 1) count++;
        }
        System.out.println(count);
    }
}