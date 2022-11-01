import java.util.*;
public class Main {
 public static void main(String... args) {
     Scanner input = new Scanner(System.in);
     int n = input.nextInt();
     int[] arr = new int[5];
     
     for (int i = 0; i < n; i++) arr[input.nextInt()]++;
     
     arr[0] = arr[4];
     arr[0] += arr[3];
     arr[1] -= arr[3];
     arr[0] += arr[2]/2;
     if (arr[2]%2 == 1) {
      arr[0]++;
      arr[1]-=2;
     }
     if (arr[1] > 0) {
      arr[0] += arr[1]/4;
      if (arr[1]%4 > 0) arr[0]++;
     }
     System.out.println(arr[0]);
    }
}