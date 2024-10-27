package bookLibrary;

public class BookCollectionFullException extends Exception {
	public BookCollectionFullException() {
		super("Book collection is full");
	}
	
	public BookCollectionFullException(String s) {
		super(s);
	}
}