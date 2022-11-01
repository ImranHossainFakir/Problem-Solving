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
            int n, count;
            n = input.nextInt();
            count = 1;
            String s = input.next();

            for (int i = 1; i < n; i++) {
                if (s.charAt(i) == s.charAt(i-1)) continue;
                count++;
            }
            System.out.println(count);
        }
	}
}
