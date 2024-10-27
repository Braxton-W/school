package bankAccount;

public class BankAccount {
	private String ID;
	private String name;
	private double balance;
	private static double interestRate = 4.5;
	
	public BankAccount(String i, String n, double b) {
		ID = i;
		name = n;
		balance = b;
	}
	
	public String getID() {
		return ID;
	}
	
	public String getName() {
		return name;
	}
	
	public double getBalance() {
		return balance;
	}
	
	public static double getInterestRate() {
		return interestRate;
	}
	
	public static void updateInterestRate(double rate) {
		interestRate = rate;
	}
	
	public void displayInfo() {
		System.out.printf("ID: %s; Name: %s; Balance: $%.2f\n", ID, name, balance);
	}
	
	public boolean withdraw(double amt) {
		if(amt > balance) {
			return false;
		}
		
		this.balance -= amt;
			
		return true;
	}
	
	public void deposit(double amt) {
		this.balance += amt;
	}
	
	public boolean transfer(double amt, BankAccount[] accounts, BankAccount account) {
		if(amt > balance) {
			return false;
		}
		
		this.balance -= amt;
		account.balance += amt;
			
		return true;
	}
}
