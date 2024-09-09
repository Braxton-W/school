package week2;

import java.util.Scanner;

public class SentenceContains {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.println("Please enter a word: ");
		String word = input.nextLine();
				
		System.out.println("Please enter a sentence: ");
		String sentence = input.nextLine();
		
		System.out.println("Word: " + word + "\nSentence: " + sentence);
		
		int index = sentence.indexOf(word);
		
		// word is in sentence and immediate characters around word are letters
		if(index >= 0 && !isLetter(index - 1, sentence) && !isLetter(index + word.length(), sentence)) {
			System.out.println("The sentence contains the word entered");
		} else {
			System.out.println("The sentence does not contain the word entered");
		}
		
		input.close();
	}
	
	public static boolean isLetter(int index, String sentence) {
		// index is out of bounds
		if(index < 0 || index >= sentence.length()) {
			return false;
		} else {
			// character is not a letter
			char c = sentence.charAt(index);
			if((c >= 'A' || c <= 'Z') || (c >= 'a' || c <= 'z')) {
				return false;
			}
		}
		
		return true;
	}
}