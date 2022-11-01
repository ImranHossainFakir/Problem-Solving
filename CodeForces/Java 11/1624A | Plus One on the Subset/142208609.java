import java.util.*;
 
public class Main {
 
 public static void main(String[] args) {
  Scanner input = new Scanner(System.in);
  int t = input.nextInt();
  
  while (t-- > 0) {
   int n, min, max;
   min = Integer.MAX_VALUE;
   max = Integer.MIN_VALUE;
   n = input.nextInt();
   for (int i = 0; i < n; i++) {
    int tem = input.nextInt();
    min = Math.min(min, tem);
    max = Math.max(max,  tem);
   }
   System.out.println(max-min);
  }
 
 }
 
}