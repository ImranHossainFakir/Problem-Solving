import java.util.*;
import java.io.*;
public class Main {
 public static void main(String... args) {
  Scanner input = new Scanner(System.in);
  int t = input.nextInt();
  int[][] arr = new int[10][10];
  
  for (int i = 1; i < 10; i++) {
   int tem = i; 
   for (int j = 1; j < 10; j++) {
    arr[i][j] = tem;
    tem = tem*10+i;
   }
  }  
  
  while (t-- > 0 ) {
   int n, count = 0;
   n = input.nextInt();
   for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
     if (n < arr[j][i]) break;
     count++;
    }
   }
   System.out.println(count);
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