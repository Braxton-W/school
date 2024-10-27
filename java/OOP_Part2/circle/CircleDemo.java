package circle;

/**
 * A CircleDemo class for demonstrating the creation of Circles
 * @author Braxton Worsley
 */
public class CircleDemo {
	public static void main(String[] args) {
		Circle c1 = new Circle(12, "Purple");
		
		System.out.println("The area of c1 is " + c1.getArea());
		System.out.println("The color of c1 is " + c1.getColor());
		
		Circle c2 = new Circle(34, "Red");
		
		System.out.println("The area of c2 is " + c2.getArea());
		System.out.println("The area of c2 is " + c2.getColor());
	}
}