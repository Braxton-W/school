package library;

import java.util.Scanner;

public class ItemsDemo {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int ID;
		String title;
		
		System.out.println("Please enter the ID for the CD: ");
		ID = input.nextInt();
		
		System.out.println("Please enter the title for the CD: ");
		title = input.next();
		
		System.out.println("Please enter the genre for the CD: ");
		String genre = input.next();
		
		CD cd = new CD(ID, title, genre);
		
		System.out.println("CD Created!");
		cd.displayInfo();
		
		System.out.println("Please enter the ID for the Video: ");
		ID = input.nextInt();
		
		System.out.println("Please enter the title for the Video: ");
		title = input.next();
		
		System.out.println("Please enter the length for the Video: ");
		int length = input.nextInt();
		
		Video video = new Video(ID, title, length);
		
		System.out.println("Video Created!");
		video.displayInfo();
		
		System.out.println("CD equal to video? " + cd.equalTo(video));
		
		input.close();
	}
}