package week3;

import java.util.Scanner;

public class MinMaxInt {
	private int minimum;
	private int maximum;
	private String prompt;
	
	public MinMaxInt(int min, int max, String p) {
		minimum = min;
		maximum = max;
		prompt = p;
	}
	
	public static void main(String[] args) {
		int maxInt = (int)(Math.random()*101);
		MinMaxInt input = new MinMaxInt(1, maxInt, "Please enter an integer between 1 and " + maxInt + ": ");
        int num = input.getValue();
        
        System.out.println("You entered " + num);
	}
	
	public int getValue() {
		Scanner input = new Scanner(System.in);
		int num;
		
		System.out.println(prompt);
		
		num = input.nextInt();
		
		while(num < minimum || num > maximum) {
			System.out.println("Integer is not within bounds");
			System.out.println(prompt);
			
			num = input.nextInt();
		}
		
		input.close();
		
		return num;
	}
}