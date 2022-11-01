import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) {
       Scanner in = new Scanner(System.in);
       StringBuilder str = new StringBuilder();
       int n, k, a, i, ans;
       n = in.nextInt();
       k = in.nextInt();
       a = k * 2 + 1;
        i = k+1;
        k = 0;
       if (i > n % a && n % a != 0) i = n % a;
       while (i <= n) {
           k++;
           str.append(i).append(" ");
           i+=a;
       }
        System.out.println(k);
        System.out.println(str + "\n");
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