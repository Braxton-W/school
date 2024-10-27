package shape;

/**
 * ShapeDemo class to present functionality of Shape and shape classes
 * @author Braxton Worsley
 */
/* public class ShapeDemo {
	final static int NUM_OF_SHAPES = 20;
	final static int MAX_LENGTH = 20;
	
	public static void main(String[] args) {
		Shape[] shapes = new Shape[NUM_OF_SHAPES];
		double totalArea = 0;
		double totalPerimeter = 0;
		
		// output headers for formatting
		System.out.println("#  Type       Area     Perimeter");
		
		// create a shape for length of array
		// while keeping track of total area and perimeter
		for(int i = 0; i < NUM_OF_SHAPES; i++) {
			int randShapeIndex = (int)(Math.random() * 3);
			double[] possLengths = new double[3];
			Shape currShape;
			String shapeType;
			
			// get randomized lengths for each possible parameter of each shape
			for(int j = 0; j < possLengths.length; j++) {
				possLengths[j] = Math.random() * MAX_LENGTH + 1;
			}
			
			switch(randShapeIndex) {
			case 0: 
				currShape = new Rectangle(possLengths[0], possLengths[1]);
				shapeType = "Rectangle";
				
				break;
			case 1: 
				currShape = new Circle(possLengths[0]);
				shapeType = "Circle";
				
				break;
			default: 
				
				
				currShape = new Triangle(possLengths[0], possLengths[1], possLengths[2]);
				System.out.printf("Triangle sides: %.2f %.2f %.2f; Area: %.2f\n", possLengths[0], possLengths[1], possLengths[2], currShape.getArea());
				shapeType = "Triangle";
				
				break;
			}
			
			// get area and perimeter of random shape
			double area = currShape.getArea();
			double perimeter = currShape.getPerimeter();
			
			// set random shape to array position
			shapes[i] = currShape;
			
			// output shape number, type, area, and perimeter
			System.out.printf("%-2d %-10s %-8.2f %-6.2f\n", i + 1, shapeType, area, perimeter);
			
			// add random shape area and perimeter to totals
			totalArea += area;
			totalPerimeter += perimeter;
		}
		
		// output total area and perimeter of shapes
		System.out.printf("Total Area: %.2f units^2\nTotal Perimeter: %.2f units\n", totalArea, totalPerimeter);
	}
} */

public class ShapeDemo {
	final static int NUM_OF_SHAPES = 20;
	
	public static void main(String[] args) {
		// Shape[] shapes = new Shape[20];
		double totalArea = 0;
		double totalPerimeter = 0;
		
		// output headers for output formatting
		System.out.println("#  Type       Area     Perimeter");
		
		// create a shape for length of array
		// while keeping track of total area and perimeter
		for(int i = 0; i < NUM_OF_SHAPES; i++) {
			// Shape[] possShapes = new Shape[3];
			Shape currShape;
			String currShapeType;
			double[] possLengths = new double[3];
			int randShapeIndex;
			
			// get randomized lengths for each possible parameter of each shape
			for(int j = 0; j < possLengths.length; j++) {
				possLengths[j] = Math.random() * 20;
			}
			
			// create one of each shape
			// possShapes[0] = new Rectangle(possLengths[0], possLengths[1]);
			// possShapes[1] = new Circle(possLengths[0]);
			// possShapes[2] = new Triangle(possLengths[0], possLengths[1], possLengths[2]);
			
			// get random shape index
			randShapeIndex = (int)(Math.random() * 3);
			
			switch(randShapeIndex) {
			case 0: 
				currShapeType = "Rectangle";
				currShape = new Rectangle(possLengths[0], possLengths[1]);
				
				break;
			case 1: 
				currShapeType = "Circle";
				currShape = new Circle(possLengths[0]);
				
				break;
			default: 
				currShapeType = "Triangle";
				
				double side1 = Math.random() * 19 + 1;
				double side2 = Math.random() * 19 + 1;
				double side3 = Math.random() * (side1 + side2 - 1) + 1;
				
				System.out.printf("Tri sides: %.2f %.2f %.2f\n", side1, side2, side3);
				
				currShape = new Triangle(side1, side2, side3);
			}
			
			// get random shape
			// Shape currShape = possShapes[randShapeIndex];
			
			// find random shape type
			// String[] shapeTypes = {"Rectangle", "Circle", "Triangle"};
			// String shapeType = shapeTypes[randShapeIndex];
			
			// get area and perimeter of random shape
			double area = currShape.getArea();
			double perimeter = currShape.getPerimeter();
			
			// set random shape to array position
			// shapes[i] = currShape;
			
			// output shape number, type, area, and perimeter
			System.out.printf("%-2d %-10s %-8.2f %-6.2f\n", i + 1, currShapeType, area, perimeter);
			
			// add random shape area and perimeter to totals
			totalArea += area;
			totalPerimeter += perimeter;
		}
		
		// output total area and perimeter of shapes
		System.out.printf("Total Area: %.2f units^2\nTotal Perimeter: %.2f units\n", totalArea, totalPerimeter);
	}
}