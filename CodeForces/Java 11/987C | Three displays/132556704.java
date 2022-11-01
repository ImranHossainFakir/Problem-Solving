import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n, i, j, b, ans, cost;
        n = input.nextInt();
        ans = Integer.MAX_VALUE;
        int[] sizes = new int[n];
        int[] costs = new int[n];
 
        for (i = 0; i < n; i++) sizes[i] = input.nextInt();
        for (i = 0; i < n; i++) costs[i] = input.nextInt();
 
        for (i = 0; i < n; i++) {
            cost = costs[i];
            b = -1;
            for (j = 0; j < i; j++) {
                if (sizes[i] <= sizes[j]) continue;
                if (b == -1 || costs[b] > costs[j]) b = j;
            }
            if (b == -1) continue;
            cost += costs[b];
            b = -1;
 
            for (j = i + 1; j < n; j++) {
                if (sizes[i] >= sizes[j]) continue;
                if (b == -1 || costs[b] > costs[j]) b = j;
            }
            if (b == -1) continue;
            cost += costs[b];
            ans = Math.min(ans, cost);
        }
 
        System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
    }
}