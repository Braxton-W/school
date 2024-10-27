package library;

public class Video extends Items {
	private int length;
	
	public Video(int ID, String title, int length) {
		super(ID, title);
		this.length = length;
	}
	
	public Video() {
		super();
	}
	
	public boolean equalTo(Video video) {
		if(super.equalTo(video)) {
			return true;
		}
		
		return false;
	}
	
	public void displayInfo() {
		System.out.println(this.toString());
	}
	
	public String toString() {
		return super.toString() + "; Runtime Length: " + length + " minutes";
	}
}