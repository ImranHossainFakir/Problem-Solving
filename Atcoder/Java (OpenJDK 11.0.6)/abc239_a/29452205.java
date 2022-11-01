import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
        long n = input.nextInt();
        System.out.println(Math.sqrt(n*(12800000L +n)));
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