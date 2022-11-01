import java.util.*;
 
public class Main {
 
 public static void main(String[] args) {
  Scanner input = new Scanner(System.in);
  int n = input.nextInt();
  int a, b;
  a = n%2 == 0 ? 4 : 9;
  b = n%2 == 0 ? n-4 : n-9;
  System.out.println(a + " " + b);
 }
}