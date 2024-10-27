package shapeAbstract;

public class ShapeDemo {
	public static void main(String[] args) {
    	Circle circle = new Circle(5);
        circle.setColor("Red");
        
        Rectangle rectangle = new Rectangle(4, 6);
        rectangle.setColor("Blue");
        
        Triangle triangle = new Triangle(3, 4, 5);
        triangle.setColor("Green");
        
        System.out.println("Shape      Area   Perimeter  Color");
        System.out.printf("Circle     %-6.2f %-10.2f %s\n", circle.getArea(), circle.getPerimeter(), circle.getColor());
        System.out.printf("Rectangle  %-6.2f %-10.2f %s\n", rectangle.getArea(), rectangle.getPerimeter(), rectangle.getColor());
        System.out.printf("Triangle   %-6.2f %-10.2f %s\n", triangle.getArea(), triangle.getPerimeter(), triangle.getColor());
	}
}