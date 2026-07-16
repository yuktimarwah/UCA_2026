import java.util.Scanner;

public class optimizedEvenFibSum {
	
	static int evenFibSum(int n) {
	if (n < 2)
		return 0;

	int sum = 0;

	int prev = 2;
	int curr = 8;

	while (prev <= n) {
		sum += prev;

		int next = 4 * curr + prev;
		prev = curr;
		curr = next;
        }

	return sum;
   }

public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);

	int n = sc.nextInt();

	System.out.println(evenFibSum(n));
     }
}
