package week3;

public class ExponentialGrowth {
	public static void main(String[] args) {
		final double oxRate = 15, elephantRate = 35;
		double oxPop = 100, elephantPop = 10;
		int years = 0;
		
		System.out.println("Ox population: " + oxPop + "; Elephant population: " + elephantPop);
		System.out.println("Ox growth rate: " + oxRate + "; Elephant growth rate: " + elephantRate);
		
		while(oxPop >= elephantPop) {
			oxPop += oxRate / 100 * oxPop;
			elephantPop += elephantRate / 100 * elephantPop;
			
			years++;
		}
		
		System.out.println("It will take " + years + " years for the elphant population to overtake the ox population");
	}
}