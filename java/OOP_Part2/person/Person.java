package ecu;

public class Person {
	// instance variables
	private String name;
	private String bannerID;
	
	// constructors
	public Person(String name, String bannerID) {
		this.name = name;
		this.bannerID = bannerID;
	}
	
	public Person() {
		this("N/A", "N/A");
	}
	
	// methods
	public String getName() {
		return name;
	}
	
	public String getBannerID() {
		return bannerID;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void setBannerID(String bannerID) {
		this.bannerID = bannerID;
	}
	
	public String toString() {
		return "Banner ID: " + bannerID + "; Name: " + name;
	}
}
