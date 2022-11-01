/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner input = new Scanner(System.in);
        int t = input.nextInt();

        while (t-- > 0) {
            long n, m, g, l;
            n = input.nextInt();
            m = input.nextInt();
            g = gcd(n, m);
            l = n/g*m;
            System.out.println(l/n);
        }
	}
	
	public static long gcd(long a, long b) {
        if (a % b == 0) return b;
        return gcd(b,a%b);
    }
}
