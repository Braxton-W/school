package week8;

public class CountCapitalLettersRecursion {
	public static void main(String[] args) {
		String str = "This Is My String";
		
		System.out.printf("There are %d capital letters in the string \"%s\"\n", countCapitalLettersRecursion(str, 0), str);
	}
	
	public static int countCapitalLettersRecursion(String s, int count) {
		if(s.equals("")) {
			return count;
		}
		
		if(s.charAt(0) >= 65 && s.charAt(0) <= 90) {
			count++;
		}
		
		return countCapitalLettersRecursion(s.substring(1), count);
	}
}