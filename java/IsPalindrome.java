package week3;

import java.util.Scanner;

public class IsPalindrome {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String str;
		int strLen;
		
		System.out.println("Please enter a string to check for if it is a palindrome: ");
		
		str = input.nextLine();
		strLen = str.length();
		
		input.close();
		
		for(int i = 0; i < strLen / 2; i++) {
			if(str.charAt(i) != str.charAt(strLen - 1 - i)) {
				System.out.println("The given string is not a palindrome");
				
				return;
			}
		}
		
		System.out.println("The given string is a palindrome");
	}
}