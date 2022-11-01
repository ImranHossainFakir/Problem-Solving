import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws Exception{
       Scanner in = new Scanner(System.in);
       int t = in.nextInt();
       while (t-- > 0) {
           int n, p, i, count1, count2, p1;
           n = in.nextInt();
           p = in.nextInt();
           in.nextInt();
           p1 = p;
           count1 = count2 = 0;
           int[] arr = new int[n];
           for (i = 0; i < n; i++) arr[i] = in.nextInt();
           mergeSort(arr);
           i = 1;
           while (i <= n) {
               if (arr[i-1] <= p) {
                   p -= arr[i-1];
                   count1 = i;
                   i+=2;
               } else {
                 try {
                     if (arr[i-2] <= 0) count1++;
                 } catch (ArrayIndexOutOfBoundsException ignored) { }
                 break;
               }
           }
 
           i = 2;
           while (i <= n) {
               if (arr[i-1] <= p1) {
                   p1 -= arr[i-1];
                   count2 = i;
                   i+=2;
               } else {
                   try {
                       if (arr[i-2] <= p1) count2++;
                   } catch (ArrayIndexOutOfBoundsException ignored) { }
                   break;
               }
           }
           System.out.println(Math.max(count1, count2));
       }
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