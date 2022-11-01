import java.io.*;
import java.math.*;
import java.util.*;
 
public class Main {
    public static void main(String... args) {
        Scanner input = new Scanner(System.in);
 
        int t = input.nextInt();
 
        while (t-- > 0) {
            String number = input.next();
            int ans = Integer.MAX_VALUE;
 
            outer : for (int i = 0, j; i < number.length()-1; ) {
                if (number.charAt(i) == number.charAt(i+1)) i++;
                else {
                    j = i++;
                    while (i < number.length()-1) {
                        if (number.charAt(i) == number.charAt(i+1)) i++;
                        else {
                            if (number.charAt(i)+number.charAt(j)+number.charAt(i+1) == 49+50+51) ans = Math.min(ans, i+2-j);
                            continue outer;
                        }
                    }
                }
            }
            System.out.println(ans==Integer.MAX_VALUE ? 0 : ans);
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