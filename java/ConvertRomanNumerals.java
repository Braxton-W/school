package week3;

import java.util.Scanner;

public class ConvertRomanNumerals {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String romanNum = "";
		int result = 0;
		
		System.out.println("Please enter a roman numeral: ");
		
		romanNum = input.nextLine();
		
		String[] romanNumArr = romanNum.split("");
		int[] intArr = new int[romanNumArr.length];
		
		for(int i = 0; i < romanNumArr.length; i++) {
			switch(romanNumArr[i]) {
			case "I": 
				intArr[i] = 1;
				break;
			case "V": 
				intArr[i] = 5;
				break;
			case "X": 
				intArr[i] = 10;
				break;
			case "L": 
				intArr[i] = 50;
				break;
			case "C": 
				intArr[i] = 100;
				break;
			case "D": 
				intArr[i] = 500;
				break;
			case "M": 
				intArr[i] = 1000;
				break;
			}
		}
		
		boolean skip = false;
		
		for(int j = 0; j < intArr.length; j++) {
			if(!skip) {
				if(intArr.length > j + 1) {
					if(intArr[j] >= intArr[j + 1]) {
						result += intArr[j];
					} else {
						result += intArr[j + 1];
						result -= intArr[j];
						skip = true;
					}
				} else {
					result += intArr[j];
				}
			} else {
				skip = false;
			}
		}
		
		System.out.println("The roman numeral " + romanNum + " resolves to " + result);
		
		input.close();
	}
}