import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n, i, ans;
        n = input.nextInt();
        ans = 0;
        i = 1;
        char[] string = input.next().toCharArray();
        char[] rgb = new char[35];
        rgb[2] = 'R';rgb[7] = 'R';rgb[12] = 'R';rgb[18] = 'G';rgb[23] = 'B';rgb[34] = 'G';
 
 
        while (i < n-1) {
            if (string[i] == string[i-1]) {
                ans++;
                string[i] = rgb[string[i]+string[i+1]-130];
                i+=2;
            } else i++;
        }
        if (n > 1 && string[n-1] == string[n-2]) {
            ans++;
            string[n-1] = rgb[string[n-1]+string[n-2]-130];
        }
        System.out.println(ans);
 
        for (char c : string) System.out.print(c);
        System.out.println();
    }
}