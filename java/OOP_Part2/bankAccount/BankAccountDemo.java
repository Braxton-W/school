package bankAccount;

import java.util.Scanner;

public class BankAccountDemo {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		BankAccount[] accounts = new BankAccount[100];
		BankAccount current = accounts[0], account;
		int choice, accountsCount = 0;
		double amount;
		String ID;
		
		displayMenu();
		choice = input.nextInt();
		
		// while user hasn't chosen to exit system
		while(choice != 9) {
			// variable to be used for if withdraw and transfers were successful
			boolean done = false;
			
			switch(choice) {
			case 1: 
				// create new account
				if(accountsCount >= accounts.length - 1) {
					System.out.println("Max amount of accounts have been created");
										
					break;
				}
				
				System.out.println("What is the ID for the account?");
				ID = input.next();
				
				account = findAccount(accounts, ID);
				
				while(account != null) {
					System.out.printf("Account with ID %s already exists\n", ID);
					
					System.out.println("What is the ID for the account?");
					
					ID = input.next();
					
					account = findAccount(accounts, ID);
				}
				
				System.out.println("What is the name for the account?");
				String name = input.next();
				
				System.out.println("How much is the initial deposit?");
				amount = input.nextDouble();
				
				// create account
				accounts[accountsCount] = new BankAccount(ID, name, amount);
				
				current = accounts[accountsCount];
				
				// System.out.printf("Account with ID %d created for %s with $%.2f\n", lastID, name, amount);
				current.displayInfo();
				
				accountsCount++;
				
				break;
			case 2: 
				// display ID, name, balance of current account
				current.displayInfo();
				
				break;
			case 3: 
				// withdraw
				if(current == null) {
					System.out.println("No bank account selected");
					System.out.println("Please create an account");
					
					break;
				}
				
				// System.out.println("Available balance: " + current.getBalance());
				current.displayInfo();
				System.out.println("How much would you like to withdraw?");
				
				amount = input.nextDouble();
				
				done = current.withdraw(amount);
				
				// if withdraw was successful
				if(done) {
					System.out.printf("Withdraw of $%.2f from account %s: %s\n", amount, current.getID(), current.getName());
					// System.out.printf("New balance: $%.2f\n", current.getBalance());
					current.displayInfo();
				} else {
					System.out.println("Withdraw could not be completed done to insufficient funds");
				}
				
				break;
			case 4: 
				// deposit
				if(current == null) {
					System.out.println("No bank account selected");
					System.out.println("Please create an account");
					
					break;
				}
				
				System.out.println("How much would you like to deposit?");
				
				amount = input.nextDouble();
				
				current.deposit(amount);
				
				System.out.printf("Deposited $%.2f into account %s: %s\n", amount, current.getID(), current.getName());
				// System.out.printf("New balance: $%.2f\n", current.getBalance());
				current.displayInfo();
				
				break;
			case 5: 
				// transfer amount from current to given account
				if(current == null) {
					System.out.println("No bank account selected");
					System.out.println("Please create an account");
					
					break;
				}
				
				System.out.println("Which account would you like to transfer to?");
				ID = input.next();
				
				// validate given account ID
				account = findAccount(accounts, ID);
				
				if(account == null) {
					System.out.println("Account does not exist");
										
					break;
				}
				
				// System.out.printf("Available balance: $%.2f\n", current.getBalance());
				current.displayInfo();
				System.out.println("How much would you like to transfer?");
				
				amount = input.nextDouble();
				
				done = current.transfer(amount, accounts, account);
				
				// if transfer was successful
				if(done) {
					System.out.printf("Transfer of $%.2f from account %s: %s to account %s: %s complete\n", amount, current.getID(), current.getName(), account.getID(), account.getName());
					System.out.printf("Account %s: %s has a balance of $%.2f\n", current.getID(), current.getName(), current.getBalance());
					System.out.printf("Account %s: %s has a balance of $%.2f\n", account.getID(), account.getName(), account.getBalance());
				} else {
					System.out.println("Transfer could not be completed");
				}
				
				break;
			case 6: 
				// view all accounts and total balance
				if(current == null) {
					System.out.println("No bank accounts");
					System.out.println("Please create a new account");
					
					break;
				}
								
				double totalBalance = 0;
				
				for(int i = 0; i < accountsCount; i++) {
					BankAccount currentAccount = accounts[i];
					
					// System.out.printf("Account %s: %s has a balance of $%.2f\n", current.getID(), current.getName(), current.getBalance());
					currentAccount.displayInfo();
					
					totalBalance += currentAccount.getBalance();
				}
				
				System.out.printf("%d accounts with total balance of $%.2f\n", accountsCount, totalBalance);
				
				break;
			case 7: 
				// view and update interest rate
				System.out.printf("The current interest rate is %.2f%%\n", BankAccount.getInterestRate());
				System.out.println("What is the new interest rate?");
				
				double rate = input.nextDouble();
				
				BankAccount.updateInterestRate(rate);
				
				System.out.printf("New interest rate is %.2f%%\n", BankAccount.getInterestRate());
				
				break;
			case 8: 
				// switch account
				if(current == null) {
					System.out.println("No bank accounts");
					System.out.println("Please create a new account");
					
					break;
				}
				
				System.out.println("What is the ID of the account to switch to?");
				
				ID = input.next();
				
				account = findAccount(accounts, ID);
				
				if(account == null) {
					System.out.println("Account does not exist");
					
					break;
				}
				
				current = account;
				
				System.out.println("Account switched!");
				current.displayInfo();
				
				break;
			default: 
				System.out.println("Invalid choice");
			}
			
			displayMenu();
			choice = input.nextInt();
		}
		
		System.out.println("Thank you for using the bank system!");
		
		input.close();
	}
	
	public static void displayMenu() {
		System.out.println("\nPlease choose from the menu: ");
		System.out.println("1. Create new account");
		System.out.println("2. Check balance");
		System.out.println("3. Withdraw");
		System.out.println("4. Deposit");
		System.out.println("5. Transfer");
		System.out.println("6. View all accounts");
		System.out.println("7. Update interest rate");
		System.out.println("8. Switch account");
		System.out.println("9. Exit");
	}
	
	public static BankAccount findAccount(BankAccount[] accounts, String ID) {
		BankAccount account = null;
		
		for(int i = 0; i < accounts.length; i++) {
			BankAccount currentAccount = accounts[i];
			
			if(currentAccount == null) {
				break;
			}
			
			if(currentAccount.getID().equals(ID)) {
				account = currentAccount;
			}
		}
		
		return account;
	}
}
