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

            int a, b, ans;
            a = input.nextInt();
            b = input.nextInt();
            ans = b;
            for (int i = 0; i < a; i++) {
                b += input.nextInt();
                ans = Math.max(ans, b);
            }
            System.out.println(ans);
        }
	}
}
