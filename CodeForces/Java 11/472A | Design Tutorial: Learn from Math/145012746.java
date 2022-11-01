import java.util.*;
 
public class Main {
 
 public static void main(String[] args) {
  Scanner input = new Scanner(System.in);
  int n = input.nextInt();
  
  if (n % 2 == 0) {
   int tem = n/2;
   if (tem%2==0) System.out.println(tem + " " + tem);
   else System.out.println((tem-1) + " " + (tem+1));
  } else {
   boolean flag = true;
   int a, b;
   a = 4;
   b = n-4;
   outer : while (flag) {
    for (int i = 2; i <= Math.sqrt(b); i++) {
     if (b % i == 0) {
      flag = false;
      continue outer;
     }
    }
    a++;
    b--;
    for (int i = 2; i <= Math.sqrt(a); i++) {
     if (a % i == 0) {
      flag = false;
      continue outer;
     }
    }
    a++;
    b--;
   }
   System.out.println(a + " " + b);
  }
 }
}