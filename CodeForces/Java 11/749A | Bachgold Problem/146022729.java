import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
 
        System.out.println(n/2);
        for (int i = 0; i < n/2-1; i++) System.out.print(2+" ");
 
        System.out.println(2+n%2);
 
    }
}