package numbers;

public class Complex implements Numbers {
	private int real;
	private int imaginary;
	
	public Complex(int real, int imaginary) {
		this.real = real;
		this.imaginary = imaginary;
	}
	
	@Override
	public Complex add(Numbers two) {
		if(two instanceof Complex) {
			Complex other = (Complex) two;
			
			return new Complex(this.real + other.real, this.imaginary + other.imaginary);
		}
		throw new IllegalArgumentException("Invalid type: Expected a Complex Number");
	}
	
	@Override
	public Complex subtract(Numbers two) {
		if(two instanceof Complex) {
			Complex other = (Complex) two;
			
			return new Complex(this.real - other.real, this.imaginary - other.imaginary);
		}
		throw new IllegalArgumentException("Invalid type: Expected a Complex Number");
	}
	
	@Override
	public String toString() {
		return real + "+" + imaginary + "i";
	}
}