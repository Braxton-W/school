package circle;

/** 
 * A Circle class to create a circle with a radius and color
 * @author Braxton Worsley
 */
public class Circle {
	// part 1: attributes
	private double radius;
	private String color;

	// part 2: constructor
	/**
	 * create a circle object from given radius and color
	 * @param r radius for new circle
	 * @param c color for new circle
	 */
	public Circle(double r, String c) {
		radius = r;
		color = c;
	}
	
	// default constructor
	/**
	 * create a default circle object with radius of 1 and color Purple
	 */
	public Circle() {
		radius = 1;
		color = "Purple";
	}
	
	// part 3: methods
	// get area of circle
	/**
	 * return area of circle
	 * @return circle area with type double
	 */
	public double getArea() {
		return Math.PI * radius * radius;
	}
	
	// get color of circle
	/**
	 * return color of circle
	 * @return circle color with type String
	 */
	public String getColor() {
		return color;
	}
	
	// change radius of circle
	/**
	 * change the radius of circle
	 * @param r new radius for circle
	 */
	public void changeRadius(double r) {
		radius = r;
	}
	
	// merge two circles
	/**
	 * merges two circles
	 * @param c2 circle to merge with another circle
	 */
	/* public void merge(Circle c2) {
		double area = this.getArea() + c2.getArea();
		radius += c2.radius;
		
		c2 = null;
	} */
}
