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
			int n, x, y, ans = 0;
			n = input.nextInt();
			x = input.nextInt();
			y = input.nextInt();
			while (n > 99) {
				ans+= Math.min(x, 25*y);
				n-=100;
			}
			if (n > 0) ans += Math.min(x, (n/4+Integer.signum(n%4))*y);
			System.out.println(ans);
		}
	}
}
