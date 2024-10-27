package bookLibrary;

public class BookCollectionEmptyException extends Exception {
	public BookCollectionEmptyException() {
		super("Book collection is empty");
	}
	
	public BookCollectionEmptyException(String s) {
		super(s);
	}
}