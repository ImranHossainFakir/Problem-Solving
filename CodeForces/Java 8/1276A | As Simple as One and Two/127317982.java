import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
       Scanner input = new Scanner(System.in);
       int t = input.nextInt();
       while (t-- > 0) {
           int i, j, len, count;
           String string = input.next();
           StringBuilder indexes = new StringBuilder();
           count = 0;
           int[] array = new int[150000];
           len = string.length();
           for (i = 0, j = 0; i < len;) {
               if (string.charAt(i) == 'o' && i+2 < len && string.charAt(i+1) == 'n' && string.charAt(i+2) == 'e') {
                   array[j++] = i+1;
                   array[j++] = i+3;
                   i += 2;
               } else if (string.charAt(i) == 't' && i+2 < len && string.charAt(i+1) == 'w' && string.charAt(i+2) == 'o') {
                   array[j++] = i+1;
                   array[j++] = i+3;
                   i += 2;
               } else i++;
           }
           i = 1;
           while (i < j) {
               count++;
               try {
                   if (array[i] == array[i+1]) {
                       indexes.append(array[i]).append(" ");
                       i += 4;
                       continue;
                   }
               } catch (ArrayIndexOutOfBoundsException ignored) { }
               indexes.append(array[i]-1).append(" ");
               i += 2;
           }
           System.out.println(count);
           System.out.println(count == 0 ? "" : indexes);
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