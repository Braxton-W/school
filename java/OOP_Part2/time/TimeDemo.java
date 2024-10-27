package time;

import java.util.Scanner;

public class TimeDemo {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String time;
		
		System.out.println("Please enter a time with format HH:MM in 24 hour format");
		
		time = input.nextLine();
		
		input.close();
		
		try {
			System.out.println(convertTime(time));
		} catch(HourOutOfBoundsException e) {
			System.out.println(e.getMessage());
		} catch(MinuteOutOfBoundsException e) {
			System.out.println(e.getMessage());
		}
	}
	
	public static String convertTime(String time) throws HourOutOfBoundsException, MinuteOutOfBoundsException {
		String[] timeSplit = time.split(":");
		int hour = Integer.parseInt(timeSplit[0]);
		int minute = Integer.parseInt(timeSplit[1]);
		String suffix = "AM";
				
		try {
			/* if((hour < 0 || hour > 24 || minute < 0 || minute > 59) || hour == 24 && minute > 0) {
				throw new Exception("Error: Invalid Time");
			} */
			
			if(hour < 0 || hour > 23) {
				throw new HourOutOfBoundsException();
			}
			
			if(minute < 0 || minute > 59) {
				throw new MinuteOutOfBoundsException();
			}
			
			if(hour == 0) {
				hour = 12;
			} else if(hour >= 12) {
				if(hour != 12) {
					hour -= 12;
				}
				
				suffix = "PM";
			}
			
			return hour + ":" + timeSplit[1] + " " + suffix;
		}
		catch(HourOutOfBoundsException e) {
			return e.getMessage();
		}
		catch(MinuteOutOfBoundsException e) {
			return e.getMessage();
		}
		
		/* if(hour > 12) {
			hour -= 12;
		}
		
		String suffix = "AM";
		
		if(hour > 12) {
			hour -= 12;
			
			if(hour >= 12) {
				suffix = "PM";
			}
		}
		
		if(hour == 0) {
			hour = 12;
		}
		
		return hour + ":" + timeSplit[1] + suffix; */
	}
}
