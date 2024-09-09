package week2;

import java.util.Random;

public class MathLibrary {
	public static void main(String[] args) {
		// absolute value
		double absValue = Math.abs(-1.5);
		System.out.println(absValue); // 1.5
		
		// max
		double maximum = Math.max(1.1, 4.3);
		System.out.println(maximum); // 4.3
		
		// min
		double minimum = Math.min(1.1, 4.3);
		System.out.println(minimum); // 1.1
		
		// sine
		double sine = Math.sin(Math.PI / 2);
		System.out.println(sine); // 1.0
		
		// cosine
		double cosine = Math.cos(Math.PI / 2);
		System.out.println(cosine); // 6.123233995736766E-17 (0) because double
		
		// tangent
		double tangent = Math.tan(Math.PI / 4);
		System.out.println(tangent); // 0.9999999999999999 (1) because double
		
		// exponential
		double exponential = Math.exp(2); // e^2
		System.out.println(exponential); // 7.38905609893065
		
		// natural log
		double naturalLog = Math.log(2); // ln(2)
		System.out.println(naturalLog); // 0.6931471805599453
		
		// power
		double power = Math.pow(2, 3); // 2^3
		System.out.println(power); // 8.0
		
		// round
		long round = Math.round(4.3);
		System.out.println(round); // 4
		
		// random number
		// method 1
		int random = (int)(Math.random()*101); // 0-100
		System.out.println(random);
		
		// method 2
		// import java.util.Random;
		Random rand = new Random();
		int num = rand.nextInt(); // returns random number between int64 min and max
		System.out.println(num);
		num = rand.nextInt(11); // returns random number between 0 and 10
		System.out.println(num);
		
		// square root
		double sqrt = Math.sqrt(4);
		System.out.println(sqrt); // 2.0
		
		// constants: e, pi
		System.out.println(Math.E); // 2.718281828459045
		System.out.println(Math.PI); // 3.141592653589793
	}
}