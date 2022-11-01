import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) {
       Scanner in = new Scanner(System.in);
       int n, i, count;
       n = in.nextInt();
       count = 0;
       int[] arr1 = {0, 4, 8, 15, 16, 23, 42};
       int[] arr2 = new int[43];
       int[] arr3 = new int[43];
       for (i = 0; i < 6; i++) arr2[arr1[i+1]] = arr1[i];
 
       for (i = 0; i < n; i++) {
           int num = in.nextInt();
           if (num == 4) arr3[4]++;
           else if (arr3[arr2[num]] > 0) {
               arr3[arr2[num]]--;
               arr3[num]++;
               if (num == 42) count++;
           }
       }
        System.out.println(n - count * 6);
    }
 
    static class FastScanner {
        public BufferedReader br;
        public StringTokenizer st;
 
        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }
 
        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
 
        public int nextInt() {
            return Integer.parseInt(next());
        }
 
        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }
 
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