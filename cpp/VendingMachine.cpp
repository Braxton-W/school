// This program simulates the payment section of a vending machine.
// The vending machine only dispenses sodas which are priced at $1.30

#include <iostream>
using namespace std;

// Create an enumeration data type called Money
enum class Money { nickel = 5, dime = 10, quarter = 25, dollar = 100 };

const int MAXSIZE = 26;
const int PRICE = 130;

// Prints price to the screen in the format: $X.XX
// price represents an amount of money, in pennies
void PrintPrice(int price);

// Takes user input (1, 2, 3, 4) and converts it to a Money type
Money ConvertToMoney(int x);

// Prints a word to the screen stating what the Money type is
void PrintMoney(Money x);

// Prints the coins to dispense, which add up to amount
// Note: This will never need to dispense a dollar
void DispenseChange(int amount);

// Outputs amount left to pay: PRICE - deposit
// Takes input for next choice and returns choice
int OutputInput(const int PRICE, int deposit);

int main()
{
	// TODO: Write main program code
	int choice;						// choice from menu
	int deposit = 0;				// deposit amount
	Money coins[MAXSIZE];			// array of coins deposited
	int count;						// counter for number of coins deposited

	// introduction with price
	printf("*** Vending Machine ***\n\nDeposit ");
	PrintPrice(PRICE);
	printf(" for a soda.\n\n");

	// output menu; request choice
	printf("1: deposit nickel   2: deposit dime   3: deposit quarter   4: deposit dollar   5: cancel transaction\n");
	printf("Enter: > ");
	cin >> choice;

	// get deposit until choice is 5 or deposit is sufficient
	for (count = 0; choice != 5 && deposit < PRICE; count++) {
		while (choice < 1 || choice > 5) {
			choice = OutputInput(PRICE, deposit);
		}

		if (choice != 5) {
			Money money = ConvertToMoney(choice);
			coins[count] = money;
			deposit += (int)money;

			if (deposit < PRICE) {
				choice = OutputInput(PRICE, deposit);
			}
		}
	}

	// cancel transaction
	if (choice == 5) {
		printf("\nTransaction cancelled.");

		if (deposit > 0) {
			printf("\nReturning:\n>> ");

			for (int i = 0; i < count; i++) {
				PrintMoney(coins[i]);
			}
		}

		return 0;
	}
	
	// if adequate deposit, dispense soda
	// if overpaid, dispense change
	if (deposit >= PRICE) {
		printf("\nDispensing soda.\n");

		if (deposit > PRICE) {
			DispenseChange(abs(PRICE - deposit));
		}
	}

	cout << endl;
	return 0;
}

void PrintPrice(int price)
{
	// TODO: Write code for the printPrice function
	printf("$%d.%02d", price / 100, price % 100);
}

void DispenseChange(int amount)
{
	// TODO: Write code for the DispenseChange function
	printf("\nChange owed: ");
	PrintPrice(amount);

	printf("\nReturning:\n>> ");

	while (amount > 0) {
		int money;

		if (amount >= (int)Money::quarter) {
			money = (int)Money::quarter;
		}
		else if (amount >= (int)Money::dime) {
			money = (int)Money::dime;
		}
		else {
			money = (int)Money::nickel;
		}

		PrintMoney((Money)money);

		amount -= money;
	}
}

Money ConvertToMoney(int x)
{
	// TODO: Write code for the ConvertToMoney function
	switch (x) {
	case 1:
		return Money::nickel;
		break;
	case 2:
		return Money::dime;
		break;
	case 3:
		return Money::quarter;
		break;
	}

	return Money::dollar;
}

void PrintMoney(Money x) {
	// TODO: Write code for the PrintMoney function
	switch (x) {
	case Money::dollar:
		printf("dollar ");
		break;
	case Money::quarter:
		printf("quarter ");
		break;
	case Money::dime:
		printf("dime ");
		break;
	case Money::nickel:
		printf("nickel ");
		break;
	}
}

int OutputInput(const int PRICE, int deposit) {
	int choice;

	printf("\nAmount left to pay: ");
	PrintPrice(PRICE - deposit);
	printf("\nEnter: > ");

	cin >> choice;

	return choice;
}
