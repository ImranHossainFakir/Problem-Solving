import java.util.*;
import java.io.*;
public class Main {
 public static void main(String... args) {
  Scanner input = new Scanner(System.in);
  int t = input.nextInt();
  
  while (t-- > 0) {
   long n, b, x, y, tem = 0, ans = 0;
   n = input.nextInt();
   b = input.nextInt();
   x = input.nextInt();
   y = input.nextInt();
   
   while (n-- > 0) {
    if (ans+x <= b) ans +=x;
    else ans -= y;
    tem += ans;
   }
   System.out.println(tem);
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
 
 }
}