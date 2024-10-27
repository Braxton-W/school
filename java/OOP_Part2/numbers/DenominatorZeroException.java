package numbers;

public class DenominatorZeroException extends Exception{
	public DenominatorZeroException() {
		super("Denominator cannot be 0");
	}
	
	public DenominatorZeroException(String s) {
		super(s);
	}
}