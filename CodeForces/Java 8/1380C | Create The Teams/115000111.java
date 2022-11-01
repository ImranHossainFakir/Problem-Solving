import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
 
        while (t-- > 0) {
            int n, x, i, a, team, tem;
            n = in.nextInt();
            x = in.nextInt();
            team = 0;
            tem = 1;
            int[] arr = new int[n];
 
            for (i = 0; i < n; i++) arr[i] = in.nextInt();
            Arrays.sort(arr);
 
            for (i = n-1; i >= 0; i--) {
                if (arr[i] * tem >= x) {
                    team++;
                    tem = 1;
                } else tem++;
            }
 
            System.out.println(team);
        }
    }
}