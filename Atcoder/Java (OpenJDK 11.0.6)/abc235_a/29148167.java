import java.util.*;
public class Main {
	public static void main(String... args) {
    	Scanner input = new Scanner(System.in);
    	int n, a, b, c;
    	n = input.nextInt();
    	a = n%10;
    	b = n/10%10;
    	c = n/100;
    	
    	System.out.println((a*100+b*10+c)+(b*100+c*10+a)+(c*100+a*10+b));
    }
}