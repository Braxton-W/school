package student;

public class StudentDemo {
	public static void main(String[] args) {
		Student s1 = new Student("0", "Braxton", 3.7);
		Student s2 = new Student("1", "Mao", 4.0);
		
		System.out.printf("Student %s: %s has GPA of %.2f\n", s1.getID(), s1.getName(), s1.getGPA());
		System.out.printf("Student %s: %s has GPA of %.2f\n", s2.getID(), s2.getName(), s2.getGPA());
		
		s1.updateName("Michael");
		s2.updateName("Xiaoli");
		
		System.out.printf("Student %s is now named %s\n", s1.getID(), s1.getName());
		System.out.printf("Student %s is now named %s\n", s2.getID(), s2.getName());
	}
}