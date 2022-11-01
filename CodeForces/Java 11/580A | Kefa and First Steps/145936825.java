import java.util.*;
public class Main {
 public static void main(String... args) {
     Scanner input = new Scanner(System.in);
     int n = input.nextInt();
     int[] arr = new int[n];
     
     for (int i = 0; i < n; i++) arr[i] = input.nextInt();
     int count, ans;
     count = ans = 1; 
     
     for (int i = 1; i < n; i++) {
      if (arr[i-1] <= arr[i]) count++;
      else {
       ans = Math.max(ans, count);
       count = 1;
      }
     }
     System.out.println(Math.max(ans, count));
    }
}