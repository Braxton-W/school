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
using namespace std;

const int BUFFERSIZE = 20;
const int FILENAMESIZE = 255;
const int MAXROWS = 22;
const int MAXCOLS = 80;

// ASCII codes for special keys; for editing
const char ESC = 27;
const char LEFTARROW = 75;
const char UPARROW = 72;
const char RIGHTARROW = 77;
const char DOWNARROW = 80;
const char SPECIAL = (char)224;

/*
* Gets a filename from the user. If file can be opened for reading,
* this function loads the file's contents into canvas.
* File is a TXT file located in the SavedFiles folder.
* If file cannot be opened, error message is displayed and
* canvas is left unchanged.
*/
void loadCanvas(char canvas[][MAXCOLS]);

/*
* Gets a filename from the user. If file can be opened for writing,
* this function writes the canvas contents into the file.
* File is a TXT file located in the SavedFiles folder.
* If file cannot be opened, error message is displayed.
*/
void saveCanvas(char canvas[][MAXCOLS]);

/*
* Initializes canvas to contain all spaces.
*/
void initCanvas(char canvas[][MAXCOLS]);

/*
* Displays canvas contents on the screen, with a border
* around the right and bottom edges.
*/
void displayCanvas(char canvas[][MAXCOLS]);

/*
* Allows user to edit the canvas by moving the cursor around and
* entering characters. Editing continues until the ESC key is pressed.
*/
void editCanvas(char canvas[][MAXCOLS]);

/*
* Copies contents of the "from" canvas into the "to" canvas.
*/
void copyCanvas(char to[][MAXCOLS], char from[][MAXCOLS]);

/*
* Replaces all instances of a character in the canvas.
* oldCh is the character to be replaced.
* newCh character is the character to replace with.
*/
void replace(char canvas[][MAXCOLS], char oldCh, char newCh);

/*
* Shifts contents of the canvas by a specified number of rows and columns.
* rowValue is the number of rows by which to shift
*    positive numbers shift downward; negative numbers shift upward
* colValue is the number of rows by which to shift
*    positive numbers shift right; negative numbers shift left
*/
void moveCanvas(char canvas[][MAXCOLS], int rowValue, int colValue);

/*
* Clears a line on the output screen, then resets the cursor back to the
* beginning of this line.
* lineNum is the line number on the output screen to clear
* numOfChars is the number of characters to clear on this line
*/
void clearLine(int lineNum, int numOfChars);

/*
* Moves the cursor in the output window to a specified row and column.
* The next output produced by the program will begin at this position.
*/
void gotoxy(short row, short col);

int main()
{
	char canvas[MAXROWS][MAXCOLS];			// 2D array to represent a canvas
	char canvasCopy[MAXROWS][MAXCOLS];		// copy of the last canvas version for 'undo'
	char choice;							// user input choice for controlling program

	// TODO: write code for the main program
	initCanvas(canvas);

	do {
		// displays canvas and menu before each choice
		displayCanvas(canvas);
		printf("<E>dit / <M>ove / <R>eplace / <U>ndo / <L>oad / <S>ave / <Q>uit: ");

		// gets choice first character of choice
		cin >> choice;

		// corrects issues where user might enter a non-character value
		while (cin.fail())
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			printf("<E>dit / <M>ove / <R>eplace / <U>ndo / <L>oad / <S>ave / <Q>uit: ");
			cin >> choice;
		}

		// clears input buffer
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');

		// switch for user's choice to execute action
		switch (tolower(choice)) {
		case 'e':
			// edit canvas
			copyCanvas(canvasCopy, canvas);

			system("cls");
			displayCanvas(canvas);
			printf("Press <ESC> to stop editing\n");

			editCanvas(canvas);

			break;
		case 'm':
			// move text art within canvas
			int row, column;

			copyCanvas(canvasCopy, canvas);

			system("cls");
			displayCanvas(canvas);
			printf("Enter column units to move: ");
			cin >> column;
			printf("Enter row units to move: ");
			cin >> row;

			moveCanvas(canvas, row, column);

			break;
		case 'r':
			// replace every instance of old character with new
			char oldCh[2], newCh[2];

			copyCanvas(canvasCopy, canvas);

			system("cls");
			displayCanvas(canvas);
			printf("Enter character to replace: ");
			cin.getline(oldCh, 2);

			printf("Enter character to replace with: ");
			cin.getline(newCh, 2);

			replace(canvas, oldCh[0], newCh[0]);

			break;
		case 'u':
			// undo canvas to last version
			copyCanvas(canvas, canvasCopy);

			break;
		case 'l':
			// load text art from SavedFiles folder
			copyCanvas(canvasCopy, canvas);
			initCanvas(canvas);
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
	} while (tolower(choice) != 'q');

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
			if (rowNew >= 0 && rowNew <= MAXROWS && colNew >= 0 && colNew <= MAXCOLS)
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
	
	system("cls");
	displayCanvas(canvas);
	printf("Enter the filename (don't enter 'txt): ");
	cin.getline(fileName, FILENAMESIZE - 15);

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

	system("cls");
	displayCanvas(canvas);
	printf("Enter the filename (don't enter 'txt): ");
	cin.getline(fileName, FILENAMESIZE - 15);

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
