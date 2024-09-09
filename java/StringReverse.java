package week3;

import java.util.Scanner;

public class StringReverse {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String str;
		
		System.out.println("Please enter a string to reverse: ");
		
		str = input.nextLine();
		
		for(int i = str.length() - 1; i >= 0; i--) {
			System.out.print(str.charAt(i));
		}
		
		input.close();
	}
}