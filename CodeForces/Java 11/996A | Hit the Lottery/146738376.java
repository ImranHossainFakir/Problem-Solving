import java.util.*;
public class Main {
 public static void main(String... args) {
     Scanner input = new Scanner(System.in);
     int n =input.nextInt();
     int ans = 0;
     int[] arr = {100, 20, 10, 5, 1};
     
     for (int i = 0; i< 5; i++) {
      ans += n/arr[i];
      n %= arr[i];
     }
     System.out.println(ans);
    }
}