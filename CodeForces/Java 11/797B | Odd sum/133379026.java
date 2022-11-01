import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n, i, sum, oddCount, negMax, oddMin;
        n = input.nextInt();
        sum = oddCount = 0;
        negMax = Integer.MIN_VALUE;
        oddMin = Integer.MAX_VALUE;
 
        for (i = 0; i < n; i++) {
            int num = input.nextInt();
            if (num < 0) {
                if (num % 2 == -1 && negMax < num) negMax = num;
            }
            else {
                sum += num;
                if (num % 2 == 0) continue;
                oddCount++;
                oddMin = Math.min(oddMin, num);
            }
        }
        if (oddCount % 2 == 0) sum = Math.max((sum - oddMin), (sum + negMax));
        System.out.println(sum);
    }
}