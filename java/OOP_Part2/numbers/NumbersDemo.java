package numbers;

public class NumbersDemo {
	public static void main(String[] args) {
		// Fraction
		int oneNum = (int)(Math.random() * 20 - 10);
		int oneDenom = (int)(Math.random() * 20 - 10);
		
		int twoNum = (int)(Math.random() * 20 - 10);
		int twoDenom = (int)(Math.random() * 20 - 10);
		
		double oneDec = (double)oneNum / oneDenom;
		double twoDec = (double)twoNum / twoDenom;
		double decAdd = oneDec + twoDec;
		double decSub = oneDec - twoDec;
		
		try {
			Fraction one = new Fraction(oneNum, oneDenom);
			Fraction two = new Fraction(twoNum, twoDenom);
			
			Fraction resultAdd = one.add(two);
			System.out.printf("%s + %s = %s = %.2f\n", one.toString(), two.toString(), resultAdd.toString(), decAdd);
			
			Fraction resultSubtract = one.subtract(two);
			System.out.printf("%s - %s = %s = %.2f\n", one.toString(), two.toString(), resultSubtract.toString(), decSub);
		} 
		catch (DenominatorZeroException e) {
			System.out.println(e.getMessage());
			
			System.exit(0);
		}
		
		// Complex
		int oneReal = 3;
		int oneImaginary = 2;
		
		int twoReal = 4;
		int twoImaginary = 5;
		
		Complex cOne = new Complex(oneReal, oneImaginary);
		Complex cTwo = new Complex(twoReal, twoImaginary);
		
		Complex cResultAdd = cOne.add(cTwo);
		System.out.printf("%s + %s = %s\n", cOne.toString(), cTwo.toString(), cResultAdd.toString());
		
		Complex cResultSubtract = cOne.subtract(cTwo);
		System.out.printf("%s - %s = %s\n", cOne.toString(), cTwo.toString(), cResultSubtract.toString());
	}
}