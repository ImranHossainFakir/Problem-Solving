import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, i, ele;
        long sum = 0;
        n = in.nextInt();
 
        long[] arr = new long[600000];
        for (i = n-1; i >= 0; i--) {
            ele = in.nextInt();
            arr[ele+i] += ele;
            if (arr[ele+i] > sum) sum = arr[ele+i];
        }
 
        System.out.println(sum);
    }
}