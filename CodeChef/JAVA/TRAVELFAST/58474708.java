/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner input = new Scanner(System.in);
        int t = input.nextInt();

        while (t-- > 0) {
            int a, b;
            a = input.nextInt();
            b = input.nextInt();
            String ans = "SAME";
            if (a > b) ans = "CAR";
            else if (a < b) ans = "BIKE";
            System.out.println(ans);
        }
	}
}
