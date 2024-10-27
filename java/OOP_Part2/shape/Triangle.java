package shape;

/**
 * Triangle class to create Triangle objects and handle methods
 * @author Braxton Worsley
 */
public class Triangle implements Shape {
	private double side1;
	private double side2;
	private double side3;
	
	/**
	 * Create a Triangle object from given side lengths
	 * @param side1 Length of first side
	 * @param side2 Length of second side
	 * @param side3 Length of third side
	 */
	public Triangle(double side1, double side2, double side3) {
		this.side1 = side1;
		this.side2 = side2;
		this.side3 = side3;
	}
	
	/**
	 * Create a default Triangle with side lengths of 1 unit
	 */
	public Triangle() {
		this(1, 1, 1);
	}
	
	/**
	 * Calculates and returns area of Triangle
	 * @return Area of Triangle with type double
	 */
	public double getArea() {
		double s = this.getPerimeter() / 2;
		
		System.out.printf("%.2f, %.2f, %.2f; %.2f; %.2f\n", s-side1, s-side2, s-side3, s, s * (s - side1) * (s - side2) * (s - side3));
		
		return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
	}
	
	/**
	 * Calculates and returns perimeter of Triangle
	 * @return Perimeter of Triangle with type double
	 */
	public double getPerimeter() {
		return side1 + side2 + side3;
	}
}