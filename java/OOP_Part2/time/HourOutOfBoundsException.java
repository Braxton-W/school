package time;

public class HourOutOfBoundsException extends Exception{
	public HourOutOfBoundsException() {
		super("Hour is out of bounds");
	}
	
	public HourOutOfBoundsException(String s) {
		super(s);
	}
}