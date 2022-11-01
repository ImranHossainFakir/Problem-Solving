import java.util.*;
 
public class Main {
 
 public static void main(String[] args) {
  Scanner input = new Scanner(System.in);
  int num = input.nextInt();
  int[] arr = {4, 7, 44, 77, 47, 74, 444, 447, 474, 477, 774, 777, 744, 747};
  String ans = "NO";
  
  for(int i = 0; i < 14; i++) {
   if (num % arr[i] == 0 ) {
    ans = "YES";
    break;
   }
  }
  System.out.println(ans);
 }
}