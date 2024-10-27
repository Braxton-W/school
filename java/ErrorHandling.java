package week5;

public class ErrorHandling {
	public static void main(String[] args) {
		try {
			// code to try
			
			throw new Exception("Exception error to output");
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}
}

// example: 
/* public class DivideByZeroException {
	public DivideByZeroException() {
		super();
	}
	
	public DivideByZeroException(String s) {
		super(s);
	}
} */