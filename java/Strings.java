package week2;

public class Strings {
	public static void main(String[] args) {
		// concatenation
		String greeting = "Hello";
		String sentence = greeting + " my friend";
		System.out.println(sentence); // Hello my friend
		
		// methods
		// length()
		String s1 = "Hello World!";
		int count = s1.length();
		System.out.println(count); // 12
		
		
		// concat()
		String one = "sail";
		String two = "boat";
		String three = one + two; // ==
		String threeDupe = one.concat(two);
		System.out.println(three + " == " + threeDupe);
		
		// charAt()
		int fifthChar = s1.charAt(4);
		System.out.println(fifthChar); // 'o'
		
		// indexOf()
		// -1 if not contains
		// index if contains
		int index = s1.indexOf("o");
		System.out.println(index); // 5
		
		// compareTo()
		// - if one before two
		// 0 if equal
		// + if one after two
		int compare = one.compareTo(two);
		System.out.println(compare);
		
		// equals()
		boolean equal = one.equals(two);
		System.out.println(equal); // false
		
		// trim()
		String s1Space = "   Hello World!   ";
		String trimmed = s1Space.trim();
		System.out.println(s1Space + " -> " + trimmed); // Hello World!
		
		// extract numbers from strings
		String sNum = "123";
		int num = Integer.parseInt(sNum);
		System.out.println(num); // 123
		
		String sDou = "3.14";
		double dou = Double.parseDouble(sDou);
		System.out.println(dou); // 3.14
	}
}