import java.util.*;
 
public class Main {
 
 public static void main(String[] args) {
  Scanner input = new Scanner(System.in);
     int n = input.nextInt();
     int m = input.nextInt();
     int count = 0;
     while (true) {
      if (n > m) break;
      n = n*3;
      m = m*2;
      count++;
     }
     System.out.println(count);
 }
}