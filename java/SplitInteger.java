package week3;

import java.util.Scanner;

public class SplitInteger {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int num;
		
		System.out.println("Please enter an integer: ");
		
		num = input.nextInt();
		String numStr = Integer.toString(num);
		
		for(int i = 0; i < numStr.length(); i++) {
			System.out.println(numStr.charAt(i));
		}
		
		input.close();
	}
}