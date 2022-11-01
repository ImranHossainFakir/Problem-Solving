import java.util.*;
import java.io.*;
public class Main {
 public static void main(String... args) {
  Scanner input = new Scanner(System.in);
 
  int[] arr = {6, 8, 4, 2};
  
  int n = input.nextInt();
  if (n == 0) n = 1;
  else n = arr[n%4];
  System.out.println(n);
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