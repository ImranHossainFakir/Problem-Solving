import java.io.*;
import java.math.*;
import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
 
        int n, m, q, count;
        n = input.nextInt();
        m = input.nextInt();
        q = input.nextInt();
 
        int[][] arr = new int[n][m+1];
 
        //for (int i = 0; i < n*m; i++) arr[i/m][i%m+1] = input.nextInt();
 
        for (int i = 0; i < n; i++) {
            count = 0;
            for (int j = 1; j < m+1; j++) {
                arr[i][j] = input.nextInt();
                if (arr[i][j] == 0) count = 0;
                else count++;
                arr[i][0] = Math.max(arr[i][0], count);
            }
        }
 
        while (q-- > 0) {
            int a, b, ans = 0;
            a = input.nextInt()-1;
            b = input.nextInt();
            if (arr[a][b] == 1) arr[a][b] = 0;
            else arr[a][b] = 1;
            count = 0;
            arr[a][0] = 0;
            for (int i = 1; i < m+1; i++) {
                if (arr[a][i] == 0) count = 0;
                else count++;
                arr[a][0] = Math.max(arr[a][0], count);
            }
 
            for (int i = 0; i < n; i++) ans = Math.max(ans, arr[i][0]);
            System.out.println(ans);
        }
    }
 
    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
 
        public String next() {
            while (!st.hasMoreElements())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }
 
        public int nextInt() {
            return Integer.parseInt(next());
        }
 
        public long nextLong() {
            return Long.parseLong(next());
        }
 
        public int[] readArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) {
                a[i]=nextInt();
            }
            return a;
        }
 
        public double nextDouble() {
            return Double.parseDouble(next());
        }
 
        public int gcd(int a, int b) {
            if (a % b == 0) return b;
            return gcd(b,a%b);
        }
 
        public int lcm(int a, int b, int g) {
            return a/g*b;
        }
        public int[] sort(int[] arr) {
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
}