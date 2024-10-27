package date;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class Date {
	private int year;
	private int month;
	private int day;
	
	public Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	
	public void addDays(int days) {
		GregorianCalendar calendar = new GregorianCalendar(year, month - 1, day);
		
		calendar.add(Calendar.DAY_OF_MONTH, days);
		
        this.year = calendar.get(Calendar.YEAR);
        this.month = calendar.get(Calendar.MONTH) + 1;
        this.day = calendar.get(Calendar.DAY_OF_MONTH);
	}
	
	/*public void addDays(int days) {
	    // Create a calendar object with 0-based month for GregorianCalendar
	    GregorianCalendar calendar = new GregorianCalendar(year, month - 1, day);
	    
	    // Add days
	    calendar.add(Calendar.DAY_OF_MONTH, days);

	    // Update year, month, and day from the calendar object
	    this.year = calendar.get(Calendar.YEAR);
	    this.month = calendar.get(Calendar.MONTH) + 1;  // Adjust back to 1-based month
	    this.day = calendar.get(Calendar.DAY_OF_MONTH);
	}*/
	
	public void addWeeks(int weeks) {
		addDays(weeks * 7);
	}
	
	public int daysTo(Date date) {
		GregorianCalendar thisDate = new GregorianCalendar(year, month - 1, day);
		GregorianCalendar otherDate = new GregorianCalendar(date.year, date.month - 1, date.day);
		
		long millisecondDifference = otherDate.getTimeInMillis() - thisDate.getTimeInMillis();
		
		return (int)(Math.abs(millisecondDifference) / (1000 * 60 * 60 * 24));
	}
	
	public int getYear() {
		return year;
	}
	
	public int getMonth() {
		return month;
	}
	
	public int getDay() {
		return day;
	}
	
	public boolean isLeapYear() {
		int year = this.getYear();
		
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	}
	
	public String toString() {
		return this.getYear() + "/" + this.getMonth() + "/" + this.getDay();
	}
}
