package week1;

import java.util.Scanner;

public class Largest {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int largest = Integer.MIN_VALUE, secondLargest = Integer.MIN_VALUE;
		
		System.out.println("Please enter 10 numbers: ");
		
		for(int i = 0; i < 10; i++) {
			int current = input.nextInt();
			
			if(current > largest) {
				secondLargest = largest;
				largest = current;
			}
		}
		
		System.out.println("The largest number entered was " + largest);
		System.out.println("The second largest number entered was " + secondLargest);
		
		input.close();
	}
}