package date;

public class DateDemo {
	public static void main(String[] args) {
		Date date = new Date(2024, 9, 9);
		
		System.out.println("Date (YYYY/MM/DD): " + date.toString());
		System.out.println("Year: " + date.getYear());
		System.out.println("Month: " + date.getMonth());
		System.out.println("Day: " + date.getDay());
		System.out.println("Leap Year: " + date.isLeapYear());
		
		// get random number of days; range: 1-30
		int daysToAdd = getRandomInt(1, 30);
		
		date.addDays(daysToAdd);
		
		System.out.printf("Add %d days: %s\n", daysToAdd, date.toString());
		
		// get random number of weeks; range: 1-5
		int weeksToAdd = getRandomInt(1, 5);
		
		date.addWeeks(weeksToAdd);
		
		System.out.printf("Add %d weeks: %s\n", weeksToAdd, date.toString());
		
		// get random year; range: 2000-2100
		int newYear = getRandomInt(2000, 2100);
		// get random month; range: 1-12
		int newMonth = getRandomInt(1, 12);
		// get random day; range: 1-30
		int newDay = getRandomInt(1, 30);
		Date newDate = new Date(newYear, newMonth, newDay);
		
		int daysBetween = date.daysTo(newDate);
		
		System.out.printf("%d days between %s and %s\n", daysBetween, date.toString(), newDate.toString());
		
		Date dateAssignment = new Date(2024, 9, 15);
		Date dateGraded = new Date(2024, 10, 25);
		System.out.printf("%d days between %s and %s\n", dateAssignment.daysTo(dateGraded), dateAssignment.toString(), dateGraded.toString());
	}
	
	public static int getRandomInt(int min, int max) {
		return (int)(Math.random() * (max - min + 1)) + min;
	}
}
