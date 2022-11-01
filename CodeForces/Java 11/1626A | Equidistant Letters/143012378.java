import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
 
        while (t-- > 0) {
             String str = input.next();
             int[] arr = new int[26];
             int[] chars = new int[str.length()];
             for (int i = 0; i < str.length(); i++) arr[str.charAt(i)-97]++;
             for (int i = 0; i < 26; i++) {
                 for (int j = 0; j < arr[i]; j++) System.out.print((char)(i+97));
             }
            System.out.println();
        }
    }
 
    static class FastScanner {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer("");
    }
}