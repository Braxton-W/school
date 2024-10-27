package ecu;

public class Student extends Person {
	// instance variables
	private double GPA;
	// private String major;
	
	// constructors
	public Student(String name, String bannerID, double GPA) {
		super(name, bannerID);
		this.GPA = GPA;
	}
	
	public Student(String name, String bannerID) {
		// calls Student(String name, String bannerID, double GPA)
		this(name, bannerID, 0);
	}
	
	public Student() {
		this("N/A", "N/A", 0);
	}
	
	/* public Student extends Person(Person person, double GPA, String major) {
		this.GPA = GPA;
		this.major = major;
	} */
	
	// methods
	public double getGPA() {
		return GPA;
	}
	
	public void setGPA(double GPA) {
		this.GPA = GPA;
	}
	
	public String toString() {
		// overrides toString() from Person class
		// super.toString() calls toString from Person class
		return super.toString() + "; GPA: " + GPA;
	}
}