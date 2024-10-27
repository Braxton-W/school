package numbers;

public class Fraction implements Numbers {
	private int numerator;
	private int denominator;
	
	public Fraction(int numerator, int denominator) throws DenominatorZeroException {
		if(denominator == 0) {
			throw new DenominatorZeroException();
		}
		
		this.numerator = numerator;
		this.denominator = denominator;
	}
	
	@Override
	public Fraction add(Numbers two) {
		if(two instanceof Fraction) {
			Fraction other = (Fraction) two;
			
			/* if(this.denominator == 0 || other.denominator == 0) {
				throw new DenominatorZeroException();
			} */
			
			int sum = this.numerator * other.denominator + other.numerator * this.denominator;
			int denominator = this.denominator * other.denominator;
			int gcd = greatestCommonDivisor(sum, denominator);
			
			try {
				Fraction result = new Fraction(sum / gcd, denominator / gcd);
				
				return result;
			} catch (DenominatorZeroException e) {
				System.out.println(e.getMessage());
				
				System.exit(0);
				}
			}
		throw new IllegalArgumentException("Invalid type: Expected a Fraction");
	}
	
	@Override
	public Fraction subtract(Numbers two) {
		if(two instanceof Fraction) {
			Fraction other = (Fraction) two;
			
			/* if(this.denominator == 0 || other.denominator == 0) {
				throw new DenominatorZeroException();
			} */
			
			int diff = this.numerator * other.denominator - other.numerator * this.denominator;
			int denominator = this.denominator * other.denominator;
			int gcd = greatestCommonDivisor(diff, denominator);
			
			try {
				Fraction result = new Fraction(diff / gcd, denominator / gcd);
				
				return result;
			} catch (DenominatorZeroException e) {
				System.out.println(e.getMessage());
				
				System.exit(0);
				}
			}
		throw new IllegalArgumentException("Invalid type: Expected a Fraction");
	}
	
	public int greatestCommonDivisor(int one, int other) {
		while(other != 0) {
			int r = one % other;
			one = other;
			other = r;
		}
		
		return one;
	}
	
	@Override
	public String toString() {
		return numerator + "/" + denominator;
	}
}