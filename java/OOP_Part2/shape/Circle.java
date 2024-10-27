package shape;

/**
 * Circle class to create Circle objects and handle methods
 * @author Braxton Worsley
 */
public class Circle implements Shape {
	private double radius;
	
	/**
	 * Create a Circle object from given radius
	 * @param radius Radius of Circle
	 */
	public Circle(double radius) {
		this.radius = radius;
	}
	
	/**
	 * Create a default Circle with radius of 1 unit
	 */
	public Circle() {
		this(1);
	}
	
	/**
	 * Calculates and returns area of Circle
	 * @return Area of Circle with type double
	 */
	public double getArea() {
		return Math.PI * radius * radius;
	}
	
	/**
	 * Calculates and returns perimeter of Circle
	 * @return Perimeter of Circle with type double
	 */
	public double getPerimeter() {
		return 2 * Math.PI * radius;
	}
}