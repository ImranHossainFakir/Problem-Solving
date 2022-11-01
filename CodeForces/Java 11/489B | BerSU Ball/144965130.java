import java.util.*;
 
public class Main {
 
 public static void main(String[] args) {
  Scanner input = new Scanner(System.in);
  int b, g, ans;
  b = input.nextInt();
  int[] boys = new int[b];
  for (int i = 0; i < b; i++) boys[i] = input.nextInt();
  g = input.nextInt();
  int[] girls = new int[g];
  for (int i = 0; i < g; i++) girls[i] = input.nextInt();
  
  Arrays.sort(boys);
  Arrays.sort(girls);
  ans = 0;
  for (int i = 0, j = 0; i < b  && j < g;) {
   if (boys[i] - girls[j] > 1) j++;
   else if (girls[j]-boys[i] > 1) i++;
   else {
    ans++;
    i++;
    j++;
   }
  }
  System.out.println(ans);
 }
}