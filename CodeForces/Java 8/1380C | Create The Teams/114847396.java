import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
 
        while (t-- > 0) {
            int n, x, i, tem, teams;
            n = in.nextInt();
            x = in.nextInt();
            teams = 0;
            int[] arr = new int[100002];
            for (i = 0; i < n; i++) {
                int index, ele;
                ele = in.nextInt();
                index = x / ele + (x % ele > 0 ? 1 : 0);
                try {
                    arr[index]++;
                } catch (ArrayIndexOutOfBoundsException ignored) {
 
                }
            }
            for (i = 1; i <= 100000; i++) {
                tem = arr[i] / i;
                arr[i+1] += arr[i] - tem * i;
                teams += tem;
                n -= tem * i;
                if (n < i) break;
            }
            System.out.println(teams);
        }
    }
}