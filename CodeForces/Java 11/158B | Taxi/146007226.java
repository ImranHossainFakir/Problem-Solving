import java.util.*;
public class Main {
 public static void main(String... args) {
     Scanner input = new Scanner(System.in);
     int n = input.nextInt();
     int[] arr = new int[5];
     
     for (int i = 0; i < n; i++) arr[input.nextInt()]++;
     
     arr[0] = arr[4] + arr[3] + (int)Math.ceil(arr[2]/2.0);
     arr[1] = Math.max(0, arr[1]-(arr[3]+2*(arr[2]%2)));
     
     System.out.println(arr[0]+(int)Math.ceil(arr[1]/4.0));
    }
}