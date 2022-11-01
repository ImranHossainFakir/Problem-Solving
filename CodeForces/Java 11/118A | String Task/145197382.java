import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        String str = input.next();
 
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c == 'A' || c == 'O' || c == 'E' || c == 'I' || c == 'Y' || c == 'U' || c == 'a' || c == 'y' || c == 'e' || c == 'i' || c == 'o' || c == 'u') continue;
            if (c < 91) c += 32;
            System.out.print("."+c);
        }
    }
 
    static class FastScanner {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer("");
    }
}