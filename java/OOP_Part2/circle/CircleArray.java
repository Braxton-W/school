package circle;

/**
 * A CircleArray class to create 100 Circles with randomized radius and color
 * output each circles' radius and color, total area, and how many Circles with each color
 * @author Braxton Worsley
 */
public class CircleArray {
	public static void main(String[] args) {
		Circle[] arr = new Circle[100];
		String[] colors = {"red", "green", "blue", "purple"};
		double areaTotal = 0;
		int[] colorsCount = new int[4];
		
		for(int i = 0; i < arr.length; i++) {
			double radius = Math.random()*101;
			int randomColor = (int)(Math.random()*4);
			String color = colors[randomColor];
			
			arr[i] = new Circle(radius, color);
			
			System.out.printf("Circle %03d: radius: %3.0f units, color: %s\n", i + 1, radius, color);
			
			areaTotal += arr[i].getArea();
			colorsCount[randomColor]++;
		}
		
		System.out.printf("The total area of all 100 circles is %.2f units\n", areaTotal);
		
		for(int j = 0; j < colors.length; j++) {
			System.out.println(colorsCount[j] + " circles with color " + colors[j]);
		}
	}
}