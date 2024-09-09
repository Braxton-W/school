package week1;

import java.util.Scanner;

public class ArrayFind {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		int[] arr = {1, 2, 3, 4, 5};
		int target = 0;
		int[] indices = new int[2];
		
		System.out.println("Please enter target integer: ");
		target = input.nextInt();
		
		// check each value in the array with every other value
		// until solution is found, if any
		for(int i = 0; i < arr.length; i++) {
			for(int j = 1; j < arr.length - 1; j++) {
				// must use two different values
				if(i == j) {
					continue;
				}
				
				if(arr[i] + arr[j] == target) {
					indices[0] = j;
					indices[1] = i;
				}
			}
		}
		
		if(indices[0] == 0 && indices[1] == 0) {
			System.out.println("Values could not be found to add to " + target);
		} else {
			System.out.println("Values at index positions " + indices[0] + " and " + indices[1] + " add to " + target);
		}
		
		input.close();
	}
}
