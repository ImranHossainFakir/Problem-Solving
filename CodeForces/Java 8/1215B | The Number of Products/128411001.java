import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(System.in);
        int n, i, j, tem;
        long ans;
        n = input.nextInt();
        tem = 0;
        ans = 0;
        Vector<Integer> segments = new Vector<>();
        for (i = 0, j = 0; i < n; i++) {
            tem = input.nextInt();
            if (tem > 0) j++;
            else {
                segments.add(j);
                j = 0;
            }
        }
        if (j != 0) segments.add(j);
        if (tem < 0) segments.add(0);
 
        for (i = 0; i < segments.size(); i++) {
            tem = segments.get(i);
            ans += tem * (tem+1L) / 2;
            if (i+2 < segments.size()) {
                ans += (segments.get(i%2)+1L) * (segments.get(i+2)+1);
                segments.set(i%2, segments.get(i%2)+1+segments.get(i+2));
            }
        }
        System.out.println((n*(n+1L)/2)-ans + " " + ans);
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