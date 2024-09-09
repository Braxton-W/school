package week3;

public class BankInterest {
	public static void main(String[] args) {
		final int startAmount = 10000;
		final double rate = 6.5;
		
		double amount = startAmount;
		
		for(int i = 0; i <= 25; i++) {
			System.out.printf("Year %02d | $%8.2f\n", i, amount);
			
			amount += rate / 100 * amount;
		}
	}
}