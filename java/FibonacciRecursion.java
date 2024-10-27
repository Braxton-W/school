package week8;

public class FibonacciRecursion {
	public static void main(String[] args) {
		int num = (int)(Math.random() * 100);
		
		System.out.printf("The sum of the fibonacci sequence of %d is %d\n", num, fibonacci(num));
;	}
	
	public static long fibonacci(int n) {
		if(n == 0 || n == 1) {
			return n;
		}
		
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}