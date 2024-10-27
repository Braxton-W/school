package library;

public class Items {
	private int ID;
	private String title;
	
	public Items(int ID, String title) {
		this.ID = ID;
		this.title = title;
	}
	
	public Items() {
		this(0, "N/A");
	}
	
	public int getID() {
		return ID;
	}
	
	public String getTitle() {
		return title;
	}
	
	public void setID(int ID ) {
		this.ID = ID;
	}
	
	public void setTitle(String title) {
		this.title = title;
	}
	
	public boolean equalTo(Items items) {
		if(this.ID == items.ID && this.title.equals(items.title)) {
			return true;
		}
		
		return false;
	}
	
	public String toString() {
		return "ID: " + ID + "; Title: " + title;
	}
}
