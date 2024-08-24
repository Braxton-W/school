package week1;

import java.util.Scanner;

public class HelloJava {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.println("Hello Java!");
		System.out.println("Please enter two numbers: ");
		
		int a, b;
		a = input.nextInt();
		b = input.nextInt();
		
		System.out.println("The sum of the two numbers is: " + (a + b));
		
		input.close();
	}
}
