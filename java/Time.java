package week3;

public class Time {
	private int hour;
	private int minute;
	
	public static void main(String[] args) {
		boolean valid;
		
		// default time 0:00
		Time time = new Time();
		
		valid = time.isValid(time.hour, time.minute);
		
		System.out.printf("Time %d:%02d; valid: %b\n", time.hour, time.minute, valid);
		
		// random time
		int randomHour = (int)(Math.random() * 30);
		int randomMinute = (int)(Math.random() * 75);
		Time randomTime = new Time();
		
		System.out.printf("Attempting to set time to %d:%02d\n", randomHour, randomMinute);
		
		randomTime.setTime(randomHour, randomMinute);
		
		valid = randomTime.isValid(randomHour, randomMinute);
		
		System.out.printf("Time %d:%02d; valid: %b\n", randomTime.hour, randomTime.minute, valid);
		
		// random time AM
		int randomHourAM = (int)(Math.random() * 15);
		int randomMinuteAM = (int)(Math.random() * 75);
		Time randomTimeAM = new Time();
		
		System.out.printf("Attempting to set time to %d:%02d AM\n", randomHourAM, randomMinuteAM);
		
		randomTimeAM.setTime(randomHourAM, randomMinuteAM, true);
		
		valid = randomTime.isValid(randomHourAM, randomMinuteAM);
		
		System.out.printf("Time %d:%02d; valid: %b\n", randomTimeAM.hour, randomTimeAM.minute, valid);
	}
	
	public Time(int h, int m) {
		hour = h;
		minute = m;
	}
	
	public Time() {
		hour = 0;
		minute = 0;
	}
	
	private boolean isValid(int hour, int minute) {
		if(hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59) {
			return true;
		}
		
		return false;
	}
	
	public void setTime(int hour, int minute) {
		if(isValid(hour, minute)) {
			this.hour = hour;
			this.minute = minute;
		}
	}
	
	public void setTime(int hour, int minute, boolean isAM) {
		if(hour >= 1 && hour <= 12) {
			this.hour = hour;
			this.minute = minute;
		}
	}
}