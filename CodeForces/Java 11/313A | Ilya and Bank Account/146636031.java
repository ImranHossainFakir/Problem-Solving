import java.io.*;
import java.math.*;
import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        int index, len;
        String number = input.next();
        len = number.length();
        if (number.charAt(0) == '-') {
            index = number.charAt(len-1) > number.charAt(len-2) ? len-1 : len-2;
            if (len == 3 && number.charAt(2) == '0') System.out.println(0);
            else {
                for (int i = 0; i < len; i++) {
                    if (i == index) continue;
                    System.out.print(number.charAt(i));
                }
            }
        }
        else System.out.println(number);
    }
 
 
    public static int[] sort(int[] arr) {
        int mid, len, i, j, k;
        len = arr.length;
        mid = len/2;
        if (len == 1) {
            return arr;
        }
 
        int[] a1 = sort(Arrays.copyOfRange(arr, 0, mid));
        int[] a2 = sort(Arrays.copyOfRange(arr, mid, len));
 
        i = j = k = 0;
        while (i < a1.length && j < a2.length) {
            if (a1[i] > a2[j]) arr[k] = a2[j++];
            else arr[k] = a1[i++];
            k++;
        }
        if (i < a1.length) while (k < len) arr[k++] = a1[i++];
        else while (k < len) arr[k++] = a2[j++];
        return arr;
 
    }
}