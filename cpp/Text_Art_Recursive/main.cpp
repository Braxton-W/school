/*
* This program allows display and editing of text art (also called ASCII art).
*
* Authors: Braxton Worsley, Devonte Joyner, Ellyn Hernandez-Rodriguez,
*		   Faisal Mangal, Jonathan Walthour, Nathan Clifton
*/

#include <iostream>
#include <fstream>
#include <cctype>
#include <windows.h>
#include <conio.h>
#include "Definitions.h"
using namespace std;

int main()
{
	char canvas[MAXROWS][MAXCOLS];			// 2D array to represent a canvas
	char canvasCopy[MAXROWS][MAXCOLS];		// copy of the last canvas version for 'undo'
	char input[BUFFERSIZE];					// user input for controlling program
	char menu[] = "<E>dit / <M>ove / <R>eplace / <D>raw / <C>lear / <U>ndo / <L>oad / <S>ave / <Q>uit: ";
	int menuLen = strlen(menu);				// length of menu used for clearLine
	bool animate = false;					// whether drawing should be animated

	// TODO: write code for the main program
	initCanvas(canvas);

	do {
		// displays canvas and menu before each choice
		displayCanvas(canvas);
		printf(menu);
		cin.getline(input, BUFFERSIZE);

		// switch for user's choice to execute action
		switch (tolower(input[0])) {
		case 'e':
			// edit canvas
			copyCanvas(canvasCopy, canvas);
			clearLine(MAXROWS + 1, menuLen + 10);
			printf("Press <ESC> to stop editing\n");

			editCanvas(canvas);

			break;
		case 'm':
			// move text art within canvas
			int row, column;

			copyCanvas(canvasCopy, canvas);

			clearLine(MAXROWS + 1, menuLen + 10);
			printf("Enter column units to move: ");
			cin >> column;
			printf("Enter row units to move: ");
			cin >> row;

			moveCanvas(canvas, row, column);

			break;
		case 'r':
			// replace every instance of old character with new
			char oldCh[BUFFERSIZE], newCh[BUFFERSIZE];

			copyCanvas(canvasCopy, canvas);

			clearLine(MAXROWS + 1, menuLen + 10);
			printf("Enter character to replace: ");
			cin.getline(oldCh, BUFFERSIZE);

			printf("Enter character to replace with: ");
			cin.getline(newCh, BUFFERSIZE);

			replace(canvas, oldCh[0], newCh[0]);

			break;
		case 'd':
			// draw
			menuTwo(canvas, canvasCopy, animate);

			break;
		case 'c':
			// clear canvas
			copyCanvas(canvasCopy, canvas);
			initCanvas(canvas);

			break;
		case 'u':
			// undo canvas to last version
			copyCanvas(canvas, canvasCopy);

			break;
		case 'l':
			// load text art from SavedFiles folder
			copyCanvas(canvasCopy, canvas);
			loadCanvas(canvas);

			break;
		case 's':
			// save canvas to .txt file
			saveCanvas(canvas);

			break;
		case 'q':
			// quit; stop program
			return 0;
		default:
			// invalid character choices will fall here
			break;
		}
	} while (tolower(input[0]) != 'q');

	return 0;
}

void gotoxy(short row, short col)
{
	COORD pos = { col, row };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void clearLine(int lineNum, int numOfChars)
{
	// Move cursor to the beginning of the specified line on the console
	gotoxy(lineNum, 0);

	// Write a specified number of spaces to overwrite characters
	for (int x = 0; x < numOfChars; x++)
		cout << " ";

	// Move cursor back to the beginning of the line
	gotoxy(lineNum, 0);
}

void replace(char canvas[][MAXCOLS], char oldCh, char newCh)
{
	// TODO: write code for the function
	for (int row = 0; row < MAXROWS; row++) {
		for (int col = 0; col < MAXCOLS; col++) {
			if (canvas[row][col] == oldCh)
				canvas[row][col] = newCh;
		}
	}
}

void editCanvas(char canvas[][MAXCOLS])
{
	char input;
	int row = 0, col = 0;

	// Move cursor to row,col and then get
	// a single character from the keyboard
	gotoxy(row, col);
	input = _getch();

	// TODO: write code for the function
	while (input != ESC) {
		if (input == SPECIAL) {
			input = _getch();

			switch (input) {
			case LEFTARROW:
				col--;
				if (col < 0)
					col = 0;
				break;
			case UPARROW:
				row--;
				if (row < 0)
					row = 0;
				break;
			case RIGHTARROW:
				col++;
				if (col >= MAXCOLS)
					col = MAXCOLS - 1;
				break;
			case DOWNARROW:
				row++;
				if (row >= MAXROWS)
					row = MAXROWS - 1;
				break;
			default:
				break;
			}
		} 
		else if (input >= 32 && input <= 127) {
			canvas[row][col] = input;
			displayCanvas(canvas);
			printf("Press <ESC> to stop editing\n");
		}

		gotoxy(row, col);

		input = _getch();
	}
}

void moveCanvas(char canvas[][MAXCOLS], int rowValue, int colValue)
{
	// TODO: write code for the function
	char canvasCopy[MAXROWS][MAXCOLS]{};

	// creates a copy of the current canvas to refer to
	for (int row = 0; row < MAXROWS; row++) {
		for (int col = 0; col < MAXCOLS; col++) {
			canvasCopy[row][col] = canvas[row][col];
		}
	}

	initCanvas(canvas);

	// shifts values in array
	for (int row = 0; row < MAXROWS; row++) {
		for (int col = 0; col < MAXCOLS; col++) {
			int rowNew = row + rowValue;
			int colNew = col + colValue;

			// avoid overhang from wrapping to next row
			if (colNew >= MAXCOLS)
				canvasCopy[row][col] = ' ';

			// if {rowNew, colNew} is within canvas
			if (rowNew >= 0 && rowNew < MAXROWS && colNew >= 0 && colNew < MAXCOLS)
				canvas[rowNew][colNew] = canvasCopy[row][col];
		}
	}
}

void initCanvas(char canvas[][MAXCOLS])
{
	// TODO: write code for the function
	for (int row = 0; row < MAXROWS; row++) {
		for (int col = 0; col < MAXCOLS; col++)
			canvas[row][col] = ' ';
	}
}

void displayCanvas(char canvas[][MAXCOLS])
{
	// Clear the screen
	system("cls");

	// TODO: write code for the function
	for (int row = 0; row < MAXROWS; row++) {
		for (int col = 0; col <= MAXCOLS; col++) {
			if (col < MAXCOLS)
				cout << canvas[row][col];
			else
				cout << "|";
		}
		cout << endl;
	}

	for (int col = 0; col < MAXCOLS; col++)
		cout << "-";
	cout << endl;

}

void copyCanvas(char to[][MAXCOLS], char from[][MAXCOLS])
{
	// TODO: write code for the function
	for (int row = 0; row < MAXROWS; row++) {
		for (int col = 0; col < MAXCOLS; col++)
			to[row][col] = from[row][col];
	}
}

void saveCanvas(char canvas[][MAXCOLS])
{
	// TODO: write code for the function
	ofstream outFile;
	char fileName[FILENAMESIZE]{};
	char filePath[FILENAMESIZE]{};

	displayCanvas(canvas);
	printf("Enter the filename (don't enter 'txt): ");
	cin.getline(fileName, static_cast<streamsize>(FILENAMESIZE) - 15);

	snprintf(filePath, FILENAMESIZE, "SavedFiles\\%s.txt", fileName);

	outFile.open(filePath);

	if (!outFile)
	{
		printf("ERROR: File cannot be written.\n");
		system("pause");
		return;
	}

	for (int row = 0; row < MAXROWS; row++) {
		for (int col = 0; col < MAXCOLS; col++)
			outFile << canvas[row][col];
		outFile << '\n';
	}

	outFile.close();

	printf("File saved!\n");
	system("pause");
}

void loadCanvas(char canvas[][MAXCOLS])
{
	// TODO: write code for the function
	ifstream inFile;
	char fileName[FILENAMESIZE]{};
	char filePath[FILENAMESIZE]{};

	initCanvas(canvas);
	displayCanvas(canvas);
	printf("Enter the filename (don't enter 'txt): ");
	cin.getline(fileName, static_cast<streamsize>(FILENAMESIZE) - 15);

	snprintf(filePath, FILENAMESIZE, "SavedFiles\\%s.txt", fileName);

	inFile.open(filePath);

	if (!inFile)
	{
		printf("ERROR: File cannot be read.\n");
		system("pause");
		return;
	}

	char curr = inFile.get();
	int row = 0, col = 0;
	while (row < MAXROWS && !inFile.eof()) {
		if (curr == '\n') {
			col = 0;
			row++;
		}
		else {
			if (col < MAXCOLS)
				canvas[row][col] = curr;
			col++;
		}
		curr = inFile.get();
	}
}
