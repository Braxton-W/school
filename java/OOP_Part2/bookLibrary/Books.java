package bookLibrary;

public class Books {
	private String[] books = new String[10];
	private int numOfBooks = 0;
	
	public Books(String[] books) {
		this.books = books;
	}
	
	public Books() {
		this(new String[10]);
	}
	
	public void addBook(String title) throws BookCollectionFullException {
		int booksCount = getBooksCount();
		
		if(booksCount >= 10) {
			throw new BookCollectionFullException();
		}
		
		this.books[booksCount] = title;
		
		numOfBooks++;
	}
	
	public void removeBook(String title) throws BookCollectionEmptyException {
		int booksCount = getBooksCount();
		
		if(booksCount == 0) {
			throw new BookCollectionEmptyException();
		}
		
		boolean bookFound = false;
		
		for(int i = 0; i < booksCount; i++) {
			if(title.equals(this.books[i])) {
				bookFound = true;
			}
			
			if(!bookFound) {
				continue;
			}
			
			this.books[i] = this.books[i + 1];
		}
		
		numOfBooks--;
	}
	
	public int getBooksCount() {
		return numOfBooks;
	}
}
