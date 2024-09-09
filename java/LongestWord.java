package week3;

import java.util.Scanner;

public class LongestWord {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String sentence, longest;
		
		System.out.println("Please enter a sentence: ");
		
		sentence = input.nextLine();
		
		longest = getLongestWord(sentence);
		
		System.out.println("The longest word in the given sentence is " + longest);
		
		input.close();
	}
	
	public static String getLongestWord(String sentence) {
		String longest = "";
		String[] words = sentence.split(" ");
		
		for(int j = 0; j < words.length; j++) {
			String currentWord = words[j];
			
			if(currentWord.length() > longest.length()) {
				longest = currentWord;
			}
		}
		
		return longest;
	}
}