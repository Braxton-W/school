package time;

public class MinuteOutOfBoundsException extends Exception{
	public MinuteOutOfBoundsException() {
		super("Minute is out of bounds");
	}
	
	public MinuteOutOfBoundsException(String s) {
		super(s);
	}
}