import java.util.*;
public class Main {
 public static void main(String... args) {
     Scanner input = new Scanner(System.in);
     String str = input.next();
     
     if (str.contains("1111111") ||str.contains("0000000"))System.out.println("YES");
     else System.out.println("NO");
    }
}