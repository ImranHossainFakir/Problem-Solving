import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        int n, i, tem, j;
        n = input.nextInt();
        int[][] arr = new int[2][7];
        tem = 1;
        StringBuilder ans = new StringBuilder();
 
        for (i = 0; i < 7; i++){
            arr[0][i] = tem;
            tem *= 10;
        }
 
        for (i = 6; i > -1; i--) {
            arr[1][i] = n / arr[0][i];
            n %= arr[0][i];
        }
 
        tem = 0;
        for (i = 6; i > -1; ) {
            if (arr[1][i] == 0) {
                i--;
                continue;
            }
            int sum = 0;
            for (j = i; j > -1; j--) {
                if (arr[1][j] > 0) {
                    sum += arr[0][j];
                    arr[1][j]--;
                }
            }
            tem++;
            ans.append(sum).append(" ");
        }
        System.out.println(tem + "\n" + ans);
    }
}