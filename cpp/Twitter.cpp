/*
* Program to implement a very simplified list of tweets
* from a single simulated Twitter account
* Tweets can be added, deleted, and liked
*
* Authors: Braxton Worsley, Devonte Joyner, Ellyn Hernandez-Rodriguez,
* 	   Faisal Mangal, Jonathan Walthour, Nathan Clifton
*/

#include <iostream>
#include<limits>
using namespace std;

const int MSGSIZE = 100;	// Maximum size for a tweet message
const int CAPACITY = 10;	// Maximum number of tweets

// Structure used to define a tweet entry
struct Tweet
{
	int id;
	char msg[MSGSIZE];
	int likes;
};

/*
* Prints out an entire timeline to the screen
* timeline = timeline of tweets to be printed
* usedSize = number of tweets in the timeline
* selected = position number of currently selected tweet
*/
void displayTimeline(const Tweet timeline[], int usedSize, int selected);

/*
* Edits currently selected tweet
* with a new message entered by the user.
* timeline = timeline in which the tweet is to be edited
* usedSize = number of tweets in the timeline
* selected = position number of currently selected tweet
* If 'selected' represents a valid array position, the
* selected tweet will be updated.
* If 'selected' is not valid a 'no tweet is selected message' will be
* displayed and no changes will be made.
*/
void doEditTweet(Tweet timeline[], int usedSize, int selected);

/*
* Adds a like to the currently selected tweet.
* timeline = timeline in which the tweet is to be edited
* usedSize = number of tweets in the timeline
* selected = position number of currently selected tweet
* If 'selected' represents a valid array position, the
* selected tweet will be updated.
* If 'selected' is not valid a 'no tweet is selected message' will be
* displayed and no changes will be made.
*/
void doLikeTweet(Tweet timeline[], int usedSize, int selected);

/*
* Deleted currently selected tweet.
* timeline = timeline in from which the entry is to be deleted
* usedSize = number of tweets in the timeline
* If 'selected' represents a valid array position:
*   the selected tweet will be deleted
*   usedSize will be updated to reflect the updated number of tweets in the timeline
*   selected will be updated to -1
* If 'selected' is not valid a 'no tweet is selected message' will be
* displayed and no changes will be made.
*/
void doDeleteTweet(Tweet timeline[], int& usedSize, int& selected);

/*
* If there is room in the timeline for new tweets, then this gets
* a new tweet from the user and adds it to the timeline.
* timeline = timeline in which the tweet is to be added
* usedSize = number of tweets in the timeline
* If tweet was able to be added, returns the position number in the
* timeline of where the item was added, and usedSize will be
* updated to reflect the number of tweets now in the timeline.
* If tweet was not able to be added, returns -1, and usedSize
* remains unchanged.
*/
int doAddTweet(Tweet timeline[], int& usedSize);

/*
* Adds a new tweet to the list
* timeline = timeline in which the entry is to be added
* usedSize = number of tweets in the timeline
* message = tweet message to be added
* If tweet was able to be added, returns the position number in the
* timeline of where the item was added, and usedSize will be
* updated to reflect the number of tweets now in the timeline.
* If tweet was not able to be added, returns -1, and usedSize
* remains unchanged.
*/
int addTweet(Tweet timeline[], int& usedSize, const char message[]);

/*
* Returns the next available ID number
* timeline = timeline in which to find the highest ID
* usedSize = number of tweets in the timeline
* If timeline is empty, returns 100;
* otherwise, returns 1 + highest ID number in the timeline
*/
int getNextId(Tweet timeline[], int usedSize);

/*
* Gets a tweet id from the user. Searches a timeline to try
* to find the specified tweet by its id.
* timeline = timeline to be searched
* usedSize = number of tweets in the timeline
* If the tweet is found, the position number of where the tweet
* is stored in the timeline will be returned.  If the tweet is
* not found, a 'not found message' will be printed, and
* the value -1 will be returned.
* If timeline is empty, an 'empty' message will be printed, and
* the value -1 will be returned.
*/
int selectTweet(const Tweet timeline[], int usedSize);

/*
* Checks if a valid tweet is selected.
* usedSize = number of tweets in the timeline
* selected = position number of currently selected tweet
* If selected represents a valid array position, returns true.
* If selected is not valid, prints "No tweet is selected." and returns false.
*/
bool isValidSelection(const int usedSize, const int selected);

int main()
{
	Tweet timeline[CAPACITY];	// Twitter timeline
	int choice;			// User's menu choice
	int usedSize = 0;		// Num of tweets in the timeline
	int selected = -1;		// Currently selected tweet
	int tmp;			// Temporary variable

	// Add some starter entries for testing purposes
	selected = addTweet(timeline, usedSize, "Where do they get the seeds to plant seedless watermelons?");
	selected = addTweet(timeline, usedSize, "Waffles are just pancakes with convenient boxes to hold your syrup.");
	selected = addTweet(timeline, usedSize, "Last night I even struck up a conversation with a spider. Turns out he's a web designer.");

	do
	{
		cout << "1. Display Timeline\n";
		cout << "2. Select Tweet\n";
		cout << "3. Add New Tweet\n";
		cout << "4. Edit Selected Tweet\n";
		cout << "5. Like Selected Tweet\n";
		cout << "6. Delete Tweet\n";
		cout << "7. Exit\n";
		cout << endl;
		cout << "Select: ";

		// Get the numeric entry from the menu
		cin >> choice;

		// Corrects issues where user might enter a non-integer value
		while (cin.fail())
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Select: ";
			cin >> choice;
		}

		// Makes the 'enter' key that was pressed after the numeric entry be ignored
		// Should be used after getting any numeric input from the keyboard
		cin.ignore();

		switch (choice)
		{
		case 1:
			displayTimeline(timeline, usedSize, selected);
			break;
		case 2:
			tmp = selectTweet(timeline, usedSize);
			// if selected tweet exists, update selected variable;
			// otherwise leave it unchanged
			if (tmp > -1)
				selected = tmp;
			break;
		case 3:
			tmp = doAddTweet(timeline, usedSize);
			// if tweet was added, make it be the selected tweet;
			// otherwise leave it unchanged
			if (tmp > -1)
				selected = tmp;
			break;
		case 4:
			doEditTweet(timeline, usedSize, selected);
			break;
		case 5:
			doLikeTweet(timeline, usedSize, selected);
			break;
		case 6:
			doDeleteTweet(timeline, usedSize, selected);
			break;
		}

	} while (choice != 7);

	return 0;
}

int doAddTweet(Tweet timeline[], int& usedSize)
{
	if (usedSize >= CAPACITY) {
		printf("\nERROR: Timeline is full.\n\n");

		return -1;
	}

	char message[MSGSIZE];

	printf("Enter tweet:\n");

	cin.getline(message, MSGSIZE);
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');

	printf("\n");

	return addTweet(timeline, usedSize, message);
}

void doEditTweet(Tweet timeline[], int usedSize, int selected)
{
	printf("\n");

	if (!isValidSelection(usedSize, selected))
		return;

	printf("Enter tweet:\n");
	cin.getline(timeline[selected].msg, MSGSIZE);

	printf("\n");
}

void doLikeTweet(Tweet timeline[], int usedSize, int selected)
{
	printf("\n");

	if (!isValidSelection(usedSize, selected))
		return;

	timeline[selected].likes++;

	printf("\n");
}

void displayTimeline(const Tweet timeline[], int usedSize, int selected)
{
	printf("Tweets:\n\nSel     ID   Likes   Tweet\n");

	if (usedSize > 0) {
		for (int i = 0; i < usedSize; i++)
			printf("%-3s%7d%8d   %-s\n",
				(i == selected) ? "-->" : "",
				timeline[i].id,
				timeline[i].likes,
				timeline[i].msg
			);
	}
	else
		printf("        ***** Empty *****");

	printf("\n");
}

int addTweet(Tweet timeline[], int& usedSize, const char message[])
{
	if (usedSize >= CAPACITY) {
		return -1;
	}

	int nextId = getNextId(timeline, usedSize);

	timeline[usedSize].id = nextId;
	snprintf(timeline[usedSize].msg, MSGSIZE, message);
	timeline[usedSize].likes = 0;

	usedSize++;

	return usedSize - 1;
}

int getNextId(Tweet timeline[], int usedSize)
{
	if (usedSize > 0) {
		return timeline[usedSize - 1].id + 1;
	}

	return 100;
}

void doDeleteTweet(Tweet timeline[], int& usedSize, int& selected)
{
	printf("\n");

	if (!isValidSelection(usedSize, selected))
		return;

	for (int i = selected; i < usedSize; i++)
		timeline[i] = timeline[i + 1];

	usedSize--;
	selected = -1;

	printf("Tweet was deleted.\n\n");
}

int selectTweet(const Tweet timeline[], int usedSize)
{
	printf("\n");

	if (usedSize == 0) {
		printf("Timeline is empty.\n\n");

		return -1;
	}

	int id;

	printf("Enter ID: ");
	cin >> id;
	cin.ignore();
	printf("\n");

	for (int i = 0; i < usedSize; i++) {
		if (timeline[i].id == id)
			return i;
	}

	printf("ID was not found.\n\n");
	return -1;
}

bool isValidSelection(const int usedSize, const int selected)
{
	if (selected > -1 && selected < usedSize)
		return true;

	printf("No tweet is selected.\n\n");
	return false;
}
