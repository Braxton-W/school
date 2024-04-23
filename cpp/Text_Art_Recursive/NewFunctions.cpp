/*
* This program allows display, editing, and drawing of text art (also called ASCII art).
*
* Authors: Braxton Worsley, Devonte Joyner, Ellyn Hernandez-Rodriguez,
*		   Faisal Mangal, Jonathan Walthour, Nathan Clifton
*/

#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Definitions.h"
using namespace std;

Point::Point(DrawPoint p)
{
	row = (int)round(p.row);
	col = (int)round(p.col);
}

// https://math.stackexchange.com/questions/39390/determining-end-coordinates-of-line-with-the-specified-length-and-angle
DrawPoint findEndPoint(DrawPoint start, int len, int angle)
{
	DrawPoint end;
	end.col = start.col + len * cos(degree2radian(angle));
	end.row = start.row + len * sin(degree2radian(angle));
	return end;
}

// Use this to draw characters into the canvas, with the option of performing animation
void drawHelper(char canvas[][MAXCOLS], Point p, char ch, bool animate)
{
	// Pause time between steps (in milliseconds)
	const int TIME = 50;

	// Make sure point is within bounds
	if (p.row >= 0 && p.row < MAXROWS && p.col >= 0 && p.col < MAXCOLS)
	{
		// Draw character into the canvas
		canvas[p.row][p.col] = ch;

		// If animation is enabled, draw to screen at same time
		if (animate)
		{
			gotoxy(p.row, p.col);
			printf("%c", ch);
			Sleep(TIME);
		}
	}
}

// Fills gaps in a row caused by mismatch between match calculations and screen coordinates
// (i.e. the resolution of our 'canvas' isn't very good)
void drawLineFillRow(char canvas[][MAXCOLS], int col, int startRow, int endRow, char ch, bool animate)
{
	// determine if we're counting up or down
	if (startRow <= endRow)
		for (int r = startRow; r <= endRow; r++)
		{
			Point point(r, col);
			drawHelper(canvas, point, ch, animate);
		}
	else
		for (int r = startRow; r >= endRow; r--)
		{
			Point point(r, col);
			drawHelper(canvas, point, ch, animate);
		}
}

// Draw a single line from start point to end point
void drawLine(char canvas[][MAXCOLS], DrawPoint start, DrawPoint end, bool animate)
{
	char ch;

	Point scrStart(start);
	Point scrEnd(end);

	// vertical line
	if (scrStart.col == scrEnd.col)
	{
		ch = '|';

		drawLineFillRow(canvas, scrStart.col, scrStart.row, scrEnd.row, ch, animate);
	}
	// non-vertical line
	else
	{
		int row = -1, prevRow;

		// determine the slope of the line
		double slope = (start.row - end.row) / (start.col - end.col);

		// choose appropriate characters based on 'steepness' and direction of slope
		if (slope > 1.8)  ch = '|';
		else if (slope > 0.08)  ch = '`';
		else if (slope > -0.08)  ch = '-';
		else if (slope > -1.8) ch = '\'';
		else ch = '|';

		// determine if columns are counting up or down
		if (scrStart.col <= scrEnd.col)
		{
			// for each column from start to end, calculate row values
			for (int col = scrStart.col; col <= scrEnd.col; col++)
			{
				prevRow = row;
				row = (int)round(slope * (col - start.col) + start.row);

				// draw from previous row to current row (to fill in row gaps)
				if (prevRow > -1)
				{
					drawLineFillRow(canvas, col, prevRow, row, ch, animate);
				}
			}
		}
		else
		{
			// for each column from start to end, calculate row values
			for (int col = scrStart.col; col >= scrEnd.col; col--)
			{
				prevRow = row;
				row = (int)round(slope * (col - start.col) + start.row);

				// draw from previous row to current row (to fill in row gaps)
				if (prevRow > -1)
				{
					drawLineFillRow(canvas, col, prevRow, row, ch, animate);
				}
			}
		}
	}
}

// Draws a single box around a center point
void drawBox(char canvas[][MAXCOLS], Point center, int height, bool animate)
{
	int sizeHalf = height / 2;
	int ratio = (int)round(MAXCOLS / (double)MAXROWS * sizeHalf);

	// Calculate where the four corners of the box should be
	DrawPoint points[4];
	points[0] = DrawPoint(center.row - sizeHalf, center.col - ratio);
	points[1] = DrawPoint(center.row - sizeHalf, center.col + ratio);
	points[2] = DrawPoint(center.row + sizeHalf, center.col + ratio);
	points[3] = DrawPoint(center.row + sizeHalf, center.col - ratio);

	// Draw the four lines of the box
	for (int x = 0; x < 3; x++)
	{
		drawLine(canvas, points[x], points[x + 1], animate);
	}
	drawLine(canvas, points[3], points[0], animate);

	// Replace the corners with a better looking character
	for (int x = 0; x < 4; x++)
	{
		drawHelper(canvas, points[x], '+', animate);
	}
}

// Menu for the drawing tools
void menuTwo(char canvas[][MAXCOLS], char backupCanvas[][MAXCOLS], bool& animate)
{
	// TODO: Write the code for the function
	const int menuLen = 81;					// length of draw menu
	char input[BUFFERSIZE];					// user input for controlling program
	char menuTwo[menuLen]{};				// draw menu
	int animatePos = 11;					// position of animate char in draw menu array

	snprintf(menuTwo, menuLen, "<A>nimate: %c / <F>ill / <L>ine / <B>ox / <N>ested Boxes / <T>ree / <M>ain Menu: ", animate ? 'Y' : 'N');
	
	do {
		int row = 0, col = 0;				// (current) row and column value of canvas
		char oldCh, newCh;					// old and new canvas position value
		Point pt(row, col);					// point for use for getPoint
		Point start, end;					// start and end points of drawings
		Point center;						// center point for boxes
		int size;							// size of boxes
		int height;							// height of tree
		int startAngle = 270;				// angle of tree trunk/branches
		int branchAngle;					// angle of tree branches respective to startAngle

		// displays canvas and draw menu before each draw choice
		displayCanvas(canvas);
		printf(menuTwo);
		cin.getline(input, BUFFERSIZE);

		switch (tolower(input[0])) {
		case 'a':
			// animate; switch animate value; 'Y' || 'N'
			animate = !animate;
			menuTwo[animatePos] = animate ? 'Y' : 'N';

			break;

		case 'f':
			// fill
			clearLine(MAXROWS + 1, menuLen + 10);
			printf("Enter character to fill with from current location / <ESC> to cancel");

			newCh = getPoint(pt);
			oldCh = canvas[pt.row][pt.col];

			if (newCh == ESC)
				break;

			copyCanvas(backupCanvas, canvas);
			fillRecursive(canvas, pt.row, pt.col, oldCh, newCh, animate);

			break;

		case 'l':
			// draw line
			clearLine(MAXROWS + 1, menuLen + 10);
			printf("Type any letter to choose start point / <ESC> to cancel");
			input[0] = getPoint(start);

			if (input[0] == ESC)
				break;

			// get original char in start position
			oldCh = canvas[start.row][start.col];
			// set start position to start char
			canvas[start.row][start.col] = input[0];
			displayCanvas(canvas);

			clearLine(MAXROWS + 1, 100);
			printf("Type any letter to choose end point / <ESC> to cancel");
			input[0] = getPoint(end);

			// remove start position char from canvas
			drawHelper(canvas, start, oldCh, animate);

			if (input[0] == ESC)
				break;

			copyCanvas(backupCanvas, canvas);
			drawLine(canvas, start, end, animate);

			break;

		case 'b':
			// draw box
			clearLine(MAXROWS + 1, menuLen + 10);
			printf("Enter size: ");
			cin >> size;

			while (cin.fail() || size <= 0) {
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				clearLine(MAXROWS + 1, menuLen + 10);
				printf("Please enter a positive integer for the size: ");
				cin >> size;
			}

			clearLine(MAXROWS + 1, menuLen + 10);
			printf("Type any letter to choose box center, or <C> for screen center / <ESC> to cancel");
			input[0] = getPoint(center);

			if (input[0] == ESC)
				break;

			if (tolower(input[0]) == 'c') {
				// set box center to canvas center
				center.row = MAXROWS / 2;
				center.col = MAXCOLS / 2;
			}

			copyCanvas(backupCanvas, canvas);
			drawBox(canvas, center, size, animate);

			break;

		case 'n':
			// draw nested boxes
			clearLine(MAXROWS + 1, menuLen + 10);
			printf("Enter size of largest box: ");
			cin >> size;

			while (cin.fail() || size <= 0) {
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				clearLine(MAXROWS + 1, menuLen + 10);
				printf("Please enter a positive integer for the size: ");
				cin >> size;
			}

			clearLine(MAXROWS + 1, menuLen + 10);
			printf("Type any letter to choose box center, or <C> for screen center / <ESC> to cancel");
			input[0] = getPoint(center);

			if (input[0] == ESC)
				break;

			if (tolower(input[0]) == 'c') {
				// set box center(s) to canvas center
				center.row = MAXROWS / 2;
				center.col = MAXCOLS / 2;
			}

			copyCanvas(backupCanvas, canvas);
			drawBoxesRecursive(canvas, center, size, animate);

			break;

		case 't':
			// draw tree
			clearLine(MAXROWS + 1, menuLen + 10);
			printf("Enter approximate tree height: ");
			cin >> height;

			while (cin.fail() || height <= 0) {
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				clearLine(MAXROWS + 1, menuLen + 10);
				printf("Enter tree height: ");
				cin >> height;
			}

			clearLine(MAXROWS + 1, menuLen + 10);
			printf("Enter branch angle: ");
			cin >> branchAngle;

			while (cin.fail()) {
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				clearLine(MAXROWS + 1, menuLen + 10);
				printf("Enter branch angle: ");
				cin >> branchAngle;
			}

			clearLine(MAXROWS + 1, menuLen + 10);
			printf("Type any letter to choose base of tree, or <C> for bottom center / <ESC> to cancel");
			input[0] = getPoint(start);

			if (input[0] == ESC)
				break;

			if (tolower(input[0]) == 'c') {
				// set tree start position to canvas bottom center
				start.row = MAXROWS - 1;
				start.col = MAXCOLS / 2;
			}

			copyCanvas(backupCanvas, canvas);
			treeRecursive(canvas, start, height, startAngle, branchAngle, animate);

			break;

		default:
			// invalid character choices will fall here
			break;
		}
	} while (tolower(input[0]) != 'm');
}

// Get a single point from screen, with character entered at that point
char getPoint(Point& pt)
{
	// TODO: Write the code for the function
	char input;
	int row = 0, col = 0;

	// Move cursor to row,col and then get
	// a single character from the keyboard
	gotoxy(row, col);
	input = _getch();

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
			pt = { row, col };

			return input;
		}

		gotoxy(row, col);

		input = _getch();
	}

	return ESC;
}

// Recursively fill a section of the screen
void fillRecursive(char canvas[][MAXCOLS], int row, int col, char oldCh, char newCh, bool animate)
{
	// TODO: Write the code for the function
	drawHelper(canvas, Point(row, col), newCh, animate);

	// order of proposed movement: 
	// up, left once, down, left once, up
	// if can't go left, go right

	// go up
	if (row - 1 >= 0) {
		if (canvas[row - 1][col] == oldCh) {
			row--;
			fillRecursive(canvas, row, col, oldCh, newCh, animate);
		}
	}
	// go left
	if (col - 1 >= 0) {
		if (canvas[row][col - 1] == oldCh) {
			col--;
			fillRecursive(canvas, row, col, oldCh, newCh, animate);
		}
		// left has new char, let's try going right
		else if (canvas[row][col - 1] == newCh && canvas[row][col + 1] == oldCh) {
			col++;
			fillRecursive(canvas, row, col, oldCh, newCh, animate);
		}
	}
	// go down
	if (row + 1 < MAXROWS) {
		if (canvas[row + 1][col] == oldCh) {
			row++;
			fillRecursive(canvas, row, col, oldCh, newCh, animate);
		}
	}
	// go right
	if (col + 1 < MAXCOLS) {
		if (canvas[row][col + 1] == oldCh) {
			col++;
			fillRecursive(canvas, row, col, oldCh, newCh, animate);
		}
	}
}

// Recursively draw a tree
void treeRecursive(char canvas[][MAXCOLS], DrawPoint start, int height, int startAngle, int branchAngle, bool animate)
{
	// TODO: Write the code for the function
	// new branch height is less than 1 or start position is out of canvas range
	if (height < 3 || start.row < 0 || start.row >= MAXROWS || start.col < 0 || start.col >= MAXCOLS)
		return;

	Point end = findEndPoint(start, height / 3, startAngle);
	drawLine(canvas, start, end, animate);

	// symmetry
	treeRecursive(canvas, end, height - 2, startAngle + branchAngle, branchAngle, animate);
	treeRecursive(canvas, end, height - 2, startAngle - branchAngle, branchAngle, animate);
}

// Recursively draw nested boxes
void drawBoxesRecursive(char canvas[][MAXCOLS], Point center, int height, bool animate)
{
	// TODO: Write the code for the function
	if (height <= 1)
		return;

	drawBox(canvas, center, height, animate);

	drawBoxesRecursive(canvas, center, height - 2, animate);
}