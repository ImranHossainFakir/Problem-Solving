import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n, i, rest;
        n = input.nextInt();
        rest = 0;
        int[] days = new int[n];
 
        for (i = 0; i < n; i++) days[i] = input.nextInt();
 
        i = 0;
        if (days[i] == 0) rest++;
 
        while (++i < n) {
            if (days[i] == 0) rest++;
            else if (days[i-1] == days[i] && (days[i] == 1 || days[i] == 2)) {
                days[i] = 0;
                rest++;
            }
            else if (days[i] == 3 && days[i-1] != 3 && days[i-1] != 0) {
                days[i] = days[i-1] == 1 ? 2 : 1;
            }
        }
        System.out.println(rest);
    }
}