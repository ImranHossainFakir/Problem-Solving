import java.util.*;
public class Main {
	public static void main(String... args) {
    	Scanner input = new Scanner(System.in);
      	String str = input.next();
      	int a, b;
      	a = input.nextInt();
      	b = input.nextInt();
      	for (int i = 0; i< str.length(); i++) {
        	if (i == a-1) System.out.print(str.charAt(b-1));
          	else if (i == b-1) System.out.print(str.charAt(a-1));
          	else System.out.print(str.charAt(i));
        }
    }
}