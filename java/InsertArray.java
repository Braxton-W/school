package week2;

import java.util.Scanner;
import java.util.Arrays;

public class InsertArray {
	public static void main(String[] args) {
		int[] arr = new int[10];
		Scanner input = new Scanner(System.in);
		int num;
		
		for(int i = 0; i < arr.length - 1; i++) {
			arr[i] = (int)(Math.random()*101);
		}
		
		System.out.println("Please enter an integer to insert in the array: ");
		num = input.nextInt();
		
		Arrays.sort(arr);
		
		insert(arr, num);
		
		for(int j = 0; j < arr.length; j++) {
			System.out.print(arr[j] + " ");
		}
		
		input.close();
	}
	
	public static void insert(int[] arr, int num) {
		int index = 0;
		
		for(int i = 0; i < arr.length; i++) {
			if(arr[i] > num) {
				index = i;
				break;
			}
		}
		
		for(int j = 1; j < index; j++) {
			arr[j - 1] = arr[j];
		}
		
		arr[index - 1] = num;
	}
}