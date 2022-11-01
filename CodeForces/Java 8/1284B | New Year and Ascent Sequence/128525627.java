import java.sql.SQLOutput;
import java.util.Arrays;
import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n, count, rem, i, j;
        long ans = 0;
        rem = 0;
        n = count = input.nextInt();
        boolean[] flag = new boolean[n];
        int[] max = new int[n];
        int[] min = new int[n];
 
        for (i = 0; i < n; i++) {
            int num, tem;
            num = input.nextInt();
            max[i] = -1;
            min[i] = Integer.MAX_VALUE;
            for (j = 0; j < num; j++) {
                tem = input.nextInt();
                max[i] = Math.max(max[i], tem);
                min[i] = Math.min(min[i], tem);
                if (tem > min[i]) flag[i] = true;
            }
        }
 
        for (i = 0; i < n; i++) {
            if (flag[i]) {
                count--;
                ans += 2L * count + 1;
                max[i] = 0;
                min[i] = 0;
                rem++;
            }
        }
        mergeSort(max);
        mergeSort(min);
 
        i = rem;
        j = 0;
 
        while (i < n) {
            if (j+rem < n && max[i] > min[j+rem]) {
                j++;
            } else {
                ans += j;
                i++;
            }
        }
        System.out.println(ans);
    }
 
    static int[] mergeSort(int[] arr) {
        int last, mid, i, j, k;
        last = arr.length;
        mid = last / 2;
        i = j = k = 0;
 
        if (mid == 0) {
            int[] arr1 = {arr[0]};
            return arr1;
        }
 
        int[] arr2, arr3;
        arr2 = mergeSort(Arrays.copyOfRange(arr, 0, mid));
        arr3 = mergeSort(Arrays.copyOfRange(arr, mid, last));
 
        while (i < arr2.length && j < arr3.length) {
            if (arr2[i] < arr3[j]) arr[k++] = arr2[i++];
            else arr[k++] = arr3[j++];
        }
        if (i == arr2.length) while (j < arr3.length) arr[k++] = arr3[j++];
        else while (i < arr2.length) arr[k++] = arr2[i++];
 
        return arr;
    }
}