package week2;

import java.util.Scanner;

public class DateFormatConvert {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String date;
		
		System.out.println("Please enter a date in the format MM/DD/YY: ");
		date = input.nextLine();
		
		date = convertFormat(date);
		
		System.out.println("The date in the format DD.MM.YY is " + date);
		
		input.close();
	}
	
	public static String convertFormat(String date) {
		String[] nums = date.split("/", 3);
		
		return nums[1] + "." + nums[0] + "." + nums[2];
	}
}