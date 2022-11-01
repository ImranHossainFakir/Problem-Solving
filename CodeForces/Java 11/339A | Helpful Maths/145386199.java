import java.util.*;
public class Main {
 public static void main(String... args) {
     Scanner input = new Scanner(System.in);
       String str = input.next();
       int len = str.length();
       int[] arr = new int[3];
       
       for (int i = 0; i < len; i+=2) arr[str.charAt(i)-49]++;
       len = len/2;
       for (int i = 0; i < 3; i++) {
        while (arr[i] > 0) {
         System.out.print(i+1);
         if (len > 0) {
          System.out.print("+");
          len--;
         }
         arr[i]--;
        }
       }
    }
}