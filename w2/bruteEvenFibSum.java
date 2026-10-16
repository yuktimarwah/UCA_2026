import java.util.Scanner;

public class bruteEvenFibSum {

	static int evenFibSum(int n) {
	       int a = 1,b = 1;
               int sum = 0;
             
               while (b <= n) {
	           if (b %2 == 0) {
	               sum += b;
                    }
                   
                   int c = a + b;
                   a = b;
                   b = c;
               }

               return sum;
       }

      public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);

          int n = sc.nextInt();

          System.out.println(evenFibSum(n));
     }
}     
