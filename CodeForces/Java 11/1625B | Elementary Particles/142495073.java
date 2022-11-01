import java.util.*;
 
public class Main {
 
 public static void main(String[] args) {
  Scanner input = new Scanner(System.in);
  int t = input.nextInt();
  
  while (t-- > 0) {
   int n, max;
   max = -1;
   n = input.nextInt();
   int[] arr = new int[150001];
   int[] arr1 = new int[150001];
   for (int i = 0; i < n; i++) {
    int a = input.nextInt();
    if (arr1[a] < 1) {
     arr[a] = i;
     arr1[a]++;
    } else {
     max = Math.max(max, arr[a]+(n-i));
     arr[a] = i;
    }
   }
   System.out.println(max);
  }
 }
 
}