package shape;

/**
 * Rectangle class to create Rectangle objects and handle methods
 * @author Braxton Worsley
 */
public class Rectangle implements Shape {
	private double length;
	private double width;
	
	/**
	 * Create a Rectangle object from given length and width
	 * @param length Length of Rectangle
	 * @param width Width of Rectangle
	 */
	public Rectangle(double length, double width) {
		this.length = length;
		this.width = width;
	}
	
	/**
	 * Create a default Rectangle with length and width of 1 unit
	 */
	public Rectangle() {
		this(1, 1);
	}
	
	/**
	 * Calculates and returns area of Rectangle
	 * @return Area of Rectangle with type double
	 */
	public double getArea() {
		return length * width;
	}
	
	/**
	 * Calculates and returns perimeter of Rectangle
	 * @return Perimeter of Rectangle with type double
	 */
	public double getPerimeter() {
		return 2 * (length + width);
	}
}