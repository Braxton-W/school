/*
    Guess The Number Game

    Created by Braxton Worsley
    November 1, 2023
*/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {
    // char var used for continuation of game
    char cont = 'c';

    // seeds randomization
    srand(time(0));

    cout << "Welcome to Guess The Number!\n";

    // instead of running file for each game
    // allow user to continue playing
    // with a new random number each game
    while(cont == 'c' || cont == 'C') {
        // generate random integer [1,100]
        int num = rand() % 100 + 1;

        // attempt counter var
        int attempt = 1;

        cout << "The number is between 1 and 100.\n\n";

        // allow user up to 10 attempts
        while(attempt <= 10) {
            int guess = 0;

            cout << "Please enter your guess: ";
            cin >> guess;

            if(guess != num) {
                if(guess > num) {
                    cout << "Too big. The number is less than " << guess << endl;
                } else {
                    cout << "Too small. The number is greater than " << guess << endl;
                }
            } else {
                cout << "Just right!\n"
                    << "You guessed the number in " << attempt << " attempts!" << endl;

                break;
            }

            attempt++;
        }

        // user used all 10 attempts
        if(attempt > 10) {
            cout << "\nYou used all 10 attempts.\n"
            << "The number was " << num << endl;
        }

        // replay game with different number
        cout << "\nWould you like to play again?\n"
            << "Enter 'C' to continue." << endl;
        cin >> cont;
    }

    // user chooses to quit playing
    cout << "Thank you for playing!" << endl;

    return 0;
}
