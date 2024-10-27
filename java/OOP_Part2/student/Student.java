package student;

public class Student {
	private String id;
	private String name;
	private double gpa;

	public Student(String i, String n, double g) {
		id = i;
		name = n;
		gpa = g;
	}
	
	/* public Student(String ID, String name) {
		this(ID, name);
	} */
	
	// get id of student
	public String getID() {
		return id;
	}
	
	// get name of student
	public String getName() {
		return name;
	}
	
	// get GPA of student
	public double getGPA() {
		return gpa;
	}
	
	// change name of student
	public void updateName(String n) {
		name = n;
	}
}
