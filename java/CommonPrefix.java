package week1;

import java.util.Scanner;

public class CommonPrefix {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		String[] arr = new String[3];
		String prefix = "";
		
		System.out.println("Please enter three words: ");
		
		for(int i = 0; i < 3; i++) {
			arr[i] = input.next();
		}
		
		// find shortest words' length
		int minLength = Math.min(arr[0].length(), arr[1].length());
		minLength = Math.min(minLength, arr[2].length());
		
		// check each character in each word for if they are same
		for(int j = 0; j < minLength; j++) {
			if((arr[0].charAt(j) != arr[1].charAt(j) || arr[0].charAt(j) != arr[2].charAt(j))) {
				break;
			}
			
			prefix = prefix + arr[0].charAt(j);
		}
		
		if(prefix == "") {
			System.out.println("The words entered do no have a common prefix");
		} else {
			System.out.println("The common prefix between the words is " + prefix);
		}
		
		input.close();
	}
}
