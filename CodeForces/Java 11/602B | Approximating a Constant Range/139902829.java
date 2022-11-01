import java.util.*;
public class Main {
    public static void main(String... args) {
       Scanner input = new Scanner(System.in);
       int n, i, range, minIn, maxIn;
       range = minIn = maxIn = 0;
       n = input.nextInt();
       Vector<Integer> vector = new Vector<>();
       int[] arr = new int[n];
 
       for (i = 0; i < n; i++) arr[i] = input.nextInt();
 
       for (i = 1; i < n; i++) {
           if (arr[i] <= arr[minIn]) minIn = i;
           else if (arr[i] >= arr[maxIn]) maxIn = i;
           if (Math.abs(arr[maxIn] - arr[minIn]) > 1) {
               vector.add(range);
               int index;
               if (maxIn > minIn) {
                   index = minIn;
                   minIn = maxIn-1;
                   while (minIn-- > index) if (arr[minIn] == arr[index]) break;
                   minIn++;
               }
               else {
                   index = maxIn;
                   maxIn = minIn-1;
                   while (maxIn-- > index) if (arr[maxIn] == arr[index]) break;
                   maxIn++;
               }
               range = Math.abs(maxIn-minIn);
           }
           else range++;
       }
 
       for (i = 0; i < vector.size(); i++) if (range < vector.get(i)) range = vector.get(i);
 
       System.out.println(range+1);
    }
}