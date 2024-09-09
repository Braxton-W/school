package week2;

public class Prime {
	public static void main(String[] args) {
		int rand = (int)(Math.random()*101);
		
		if(isPrime(rand)) {
			System.out.println(rand + " is prime");
		} else {
			System.out.println(rand + " is not prime");
		}
	}
	
	public static boolean isPrime(int num) {
		for(int i = 2; i < num; i++) {
			if(num % i == 0) {
				return false;
			}
		}
		
		return true;
	}
}