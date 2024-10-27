package week7;

public class TwoDArraySearch {
	public static void main(String[] args) {
		int n = 5;
		int[][] arr = new int[n][n];
		int sum = 0;
		int largest = Integer.MIN_VALUE;
		int targetX = -1, targetY = -1;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				arr[i][j] = (int)(Math.random() * 10);
				
				System.out.print(arr[i][j] + " ");
			}
			
			System.out.println();
		}
		
		int target = (int)(Math.random() * 10);
		
		for(int k = 0; k < n; k++) {
			for(int l = 0; l < n; l++) {
				int curr = arr[k][l];
				
				sum += curr;
				
				if(curr > largest) {
					largest = curr;
				}
				
				if(curr == target && targetX == -1) {
					targetX = k;
					targetY = l;
				}
			}
		}
		
		System.out.printf("The 2D array has a sum of %d\n", sum);
		System.out.printf("Largest value of %d\n", largest);
		System.out.printf("First instance of target value %d is at (%d, %d)", target, targetX, targetY);
	}
}