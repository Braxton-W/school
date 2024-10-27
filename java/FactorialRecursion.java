package week8;

public class FactorialRecursion {
	public static void main(String[] args) {
		int num = (int)(Math.random() * 10);
		
		System.out.printf("The factorial of %d is %d\n", num, factorial(num));
	}
	
	public static long factorial(int n) {
		if(n >= 1) {
			return n * factorial(n - 1);
		}
		
		return 1;
	}
}