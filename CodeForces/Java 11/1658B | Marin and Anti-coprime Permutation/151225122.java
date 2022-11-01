import java.util.*;
import java.io.*;
public class Main {
 public static void main(String... args) {
  Scanner input = new Scanner(System.in);
  int t = input.nextInt();
  
  while (t-- > 0) {
   long n, tem;
   tem = 1;
   n = input.nextLong();
   if (n%2 == 0) {
    for (int i = 1; i <= n/2; i++) {
     tem *= i;
     tem %= 998244353;
    }
    System.out.println((tem*tem)%998244353);
   } else System.out.println(0);
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