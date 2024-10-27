package library;

public class CD extends Items {
	private String genre;
	
	public CD(int ID, String title, String genre) {
		super(ID, title);
		this.genre = genre;
	}
	
	public CD() {
		super();
	}
	
	public boolean equalTo(CD cd) {
		if(super.equalTo(cd) && cd.genre.equals(genre)) {
			return true;
		}
		
		return false;
	}
	
	public void displayInfo() {
		System.out.println(this.toString());
	}
	
	public String toString() {
		return super.toString() + "; Genre: " + genre;
	}
}