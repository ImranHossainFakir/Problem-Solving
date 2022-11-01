import java.io.*;
import java.math.*;
import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
 
        while (t-- > 0) {
            int n, count;
            n = input.nextInt();
            count = 0;
 
            int[] arr = new int[(n+1)];
 
            for (int i = 1; i <= n; i++) arr[i] = input.nextInt();
 
            for (int p1 = 0, p2 = 0, i = 1, j = n; i < j; ) {
                if (arr[i] == arr[j]) {
                    i++;
                    p1 = i-1;
                    j--;
                    p2 = n-j;
                }
                else if (arr[i] > arr[j]) {
                    arr[j-1] += arr[j--];
                }
                else {
                    arr[i+1] += arr[i++];
                }
 
 
                count = p1+p2;
            }
            System.out.println(count);
        }
    }
}
 