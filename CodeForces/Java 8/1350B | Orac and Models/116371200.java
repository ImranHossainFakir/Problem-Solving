import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
 
        while (t-- > 0) {
            int n, i, j, max;
            n = in.nextInt();
            max = 0;
            int[] arr = new int[n+1];
            int[] models = new int[n+1];
 
            for (i = 1; i <= n; i++) arr[i] = in.nextInt();
            for (i = 1; i <= n-1; i++) for (j = 2 * i; j <= n; j += i) if (arr[j] > arr[i] && models[i] >= models[j]) models[j] = models[i] + 1;
 
            for (i = 1; i <= n; i++) if (max < models[i]) max = models[i];
 
            System.out.println(max + 1);
        }
    }
}