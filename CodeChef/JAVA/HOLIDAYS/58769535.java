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
            int a, b, ans = 1;
            a = input.nextInt();
            b = input.nextInt();
            int[] arr = new int[a];
            for (int i = 0; i < a; i++) arr[i] = input.nextInt();
            Arrays.sort(arr);
            b -= arr[a-1];
            for (int i = a-2; i > -1; i--) {
                if (b < 1) break;
                ans++;
                b -= arr[i];
            }
            System.out.println(a-ans);
        }
	}
}
