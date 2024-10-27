package bookLibrary;

public class BooksDemo {
	public static void main(String[] args) {
		Books books = new Books();
		String bookOneName = "title1";
		String bookTwoName = "title2";
		
		try {
			// books.removeBook("");
			books.addBook(bookOneName);
			System.out.printf("Added book \"%s\"\n", bookOneName);
			
			books.addBook(bookTwoName);
			System.out.printf("Added book \"%s\"\n", bookTwoName);
			
			System.out.printf("Number of books: %d\n", books.getBooksCount());
			
			books.removeBook(bookOneName);
			System.out.printf("Removed book \"%s\"\n", bookOneName);
			
			System.out.printf("Number of books: %d\n", books.getBooksCount());
		}
		catch(BookCollectionFullException e) {
			System.out.println(e.getMessage());
		}
		catch(BookCollectionEmptyException e) {
			System.out.println(e.getMessage());
		}
	}
}