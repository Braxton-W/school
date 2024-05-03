/*
* Program to implement a very simplified list of tweets
* from a single simulated Twitter account
* Tweets can be added, deleted, and liked
*
* Authors: Braxton Worsley, Devonte Joyner, Ellyn Hernandez-Rodriguez,
*		   Faisal Mangal, Johnathan Walthour, Nathan Clifton
*/

#include <iostream>
using namespace std;

const int MSGSIZE = 100;	// Maximum size for a tweet message

// Structure used to define a tweet entry
struct Tweet
{
	int id;
	char msg[MSGSIZE];
	int likes;
};

struct Node
{
	Tweet tweet;
	Node* next;		// pointer to next node
};

/*
* Prints out an entire timeline to the screen
* timeline = timeline node head of tweets to be printed
* selected = pointer to node of currently selected tweet
*/
void displayTimeline(Node* timeline, Node* selected);

/*
* Edits currently selected tweet
* with a new message entered by the user.
* selected = pointer to node of currently selected tweet
* If 'selected' represents a valid node, the
* selected tweet will be updated.
* If 'selected' is not valid, a 'no tweet is selected message' will be
* displayed and no changes will be made.
*/
void doEditTweet(Node* selected);

/*
* Adds a like to the currently selected tweet.
* selected = pointer to node of currently selected tweet
* If 'selected' represents a valid node, the
* selected tweet will be updated.
* If 'selected' is not valid, a 'no tweet is selected message' will be
* displayed and no changes will be made.
*/
void doLikeTweet(Node* selected);

/*
* Deleted currently selected tweet.
* timeline = timeline node head from which the entry is to be deleted
* selected = reference to pointer to node of currently selected tweet
* If 'selected' represents a valid node,
* the selected tweet will be deleted and selected will be updated to -1
* If 'selected' is not valid, a 'no tweet is selected message' will be
* displayed and no changes will be made.
*/
void doDeleteTweet(Node*& timeline, Node*& selected);

/*
* Adds new tweet to the timeline.
* timeline = timeline node head from which the tweet is to be added
* If tweet was able to be added, returns a pointer to the node 
* in the timeline of where the item was added.
* If tweet was not able to be added, returns NULL pointer.
*/
Node* doAddTweet(Node*& timeline);

/*
* Adds a new tweet to the list
* timeline = timeline node head in which the entry is to be added
* message = tweet message to be added
* If tweet was able to be added, returns pointer to node 
* in the timeline of where the item was added.
* If tweet was not able to be added, returns NULL pointer.
*/
Node* addTweet(Node*& timeline, const char message[]);

/*
* Returns the next available ID number
* timeline = timeline node head in which to find the highest ID
* If timeline is empty, returns 100;
* otherwise, returns 1 + highest ID number in the timeline
*/
int getNextId(Node* timeline);

/*
* Gets a tweet id from the user. Searches a timeline to try
* to find the specified tweet by its node.
* timeline = timeline node head to be searched
* If the tweet is found, a pointer to the node of where the tweet
* is stored in the timeline will be returned.  If the tweet is
* not found, a 'not found message' will be printed, and
* a NULL pointer will be returned.
* If timeline is empty, an 'empty' message will be printed, and
* a NULL pointer will be returned.
*/
Node* selectTweet(Node* timeline);

/* 
* Deletes all nodes in the linked list.
* Needed since the entire linked list must be deleted 
* to clean up memory before the program ends.
* timeline = timeline node head to delete tweets
*/
void deleteList(Node*& timeline);

int main()
{
	Node* timeline = NULL;    // Twitter timeline
	int choice;               // User's menu choice
	Node* selected;           // Currently selected tweet
	Node* tmp;                // Temporary variable

	// Add some starter entries for testing purposes
	selected = addTweet(timeline, "Where do they get the seeds to plant seedless watermelons?");
	selected = addTweet(timeline, "Waffles are just pancakes with convenient boxes to hold your syrup.");
	selected = addTweet(timeline, "Last night I even struck up a conversation with a spider. Turns out he's a web designer.");

	do
	{
		cout << "1. Display Timeline\n"
			<< "2. Select Tweet\n"
			<< "3. Add New Tweet\n"
			<< "4. Edit Selected Tweet\n"
			<< "5. Like Selected Tweet\n"
			<< "6. Delete Tweet\n"
			<< "7. Exit\n\n"
			<< "Select: ";

		// Get the numeric entry from menu
		cin >> choice;

		// Corrects issues where user might enter a non-integer value
		while (cin.fail())
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			printf("Select: ");
			cin >> choice;
		}

		// ignores 'enter' key pressed after numeric entry
		cin.ignore();

		switch (choice)
		{
		case 1:
			displayTimeline(timeline, selected);
			break;
		case 2:
			tmp = selectTweet(timeline);
			// if selected tweet exists, update selected variable;
			// otherwise leave it unchanged
			if (tmp != NULL)
				selected = tmp;
			break;
		case 3:
			tmp = doAddTweet(timeline);
			// if tweet was added, make it be the selected tweet;
			// otherwise leave it unchanged
			if (tmp != NULL)
				selected = tmp;
			break;
		case 4:
			doEditTweet(selected);
			break;
		case 5:
			doLikeTweet(selected);
			break;
		case 6:
			doDeleteTweet(timeline, selected);
			break;
		}
	} while (choice != 7);

	deleteList(timeline);

	return 0;
}

Node* doAddTweet(Node*& timeline)
{
	char message[MSGSIZE];

	// get new tweet
	printf("Enter tweet:\n");
	cin.getline(message, MSGSIZE);

	// clear input buffer
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');

	printf("\n");

	// add tweet and return node where tweet added
	return addTweet(timeline, message);
}

void doEditTweet(Node* selected)
{
	printf("\n");

	// if no tweet selected
	if (selected == NULL) {
		printf("No tweet is selected.\n\n");

		return;
	}

	// get new tweet contents
	printf("Enter tweet:\n");
	cin.getline(selected->tweet.msg, MSGSIZE);

	// clear input buffer
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');

	printf("\n");
}

void doLikeTweet(Node* selected)
{
	printf("\n");

	if (selected == NULL) {
		printf("No tweet is selected.\n\n");

		return;
	}

	selected->tweet.likes++;

	printf("\n");
}

void displayTimeline(Node* timeline, Node* selected)
{
	printf("Tweets:\n\nSel     ID   Likes   Tweet\n");

	if (timeline == NULL) {
		printf("        ***** Empty *****\n");

		return;
	}

	for (Node* currentNode = timeline; currentNode != NULL; currentNode = currentNode->next) {
		printf("%-3s%7d%8d   %-s\n",
			(currentNode == selected) ? "-->" : "",
			currentNode->tweet.id,
			currentNode->tweet.likes,
			currentNode->tweet.msg
		);
	}

	printf("\n");
}

Node* addTweet(Node*& timeline, const char message[])
{
	Node* newNode = new Node;
	
	// get tweet information
	newNode->tweet.id = getNextId(timeline);
	snprintf(newNode->tweet.msg, MSGSIZE, "%s", message);
	newNode->tweet.likes = 0;

	newNode->next = NULL;

	// if empty, set node to head of timeline
	// else, set node to the end of timeline
	if (timeline == NULL)
		timeline = newNode;
	else {
		Node* currentNode = timeline;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		currentNode->next = newNode;
	}

	return newNode;
}

int getNextId(Node* timeline)
{
	int id = 100;

	if (timeline != NULL) {
		Node* currentNode = timeline;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		id = currentNode->tweet.id + 1;
	}

	return id;
}

void doDeleteTweet(Node*& timeline, Node*& selected)
{
	/* Selected will always be updated to NULL 
	*		since it points to the node which is being deleted.
	* Timeline (the head of the linked list) will only need to be updated 
	*		if the first node in the list is being deleted. */

	printf("\n");

	if (timeline == NULL || selected == NULL) {
		printf("No tweet is selected.\n\n");

		return;
	}

	// if selected node is head of timeline
	// else selected node is middle to end
	if (timeline == selected)
		timeline = timeline->next;
	else {
		// find node before selected node
		Node* currentNode = timeline;
		while (currentNode->next != selected && currentNode != NULL)
			currentNode = currentNode->next;

		// if selected node not found
		if (currentNode == NULL)
			return;

		// update next of previous node
		currentNode->next = selected->next;
	}

	delete selected;
	selected = NULL;
	printf("Tweet was deleted.\n\n");
}

Node* selectTweet(Node* timeline)
{
  printf("\n");

	if (timeline == NULL) {
		printf("Timeline is empty.\n\n");

		return NULL;
	}

	int id;

	printf("Enter ID: ");
	cin >> id;

	// Corrects issues where user might enter a non-integer value
	while (cin.fail())
	{
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		printf("Enter ID: ");
		cin >> id;
	}

	printf("\n");

	for (Node* temp = timeline; temp != NULL; temp = temp->next) {
		if (temp->tweet.id == id)
			return temp;
	}

	printf("ID was not found.\n\n");
	return NULL;
}

void deleteList(Node*& timeline)
{
	// check base case
	if (timeline == NULL)
		return;

	// recursive cases
	deleteList(timeline->next);

	// delete as coming back from NULL to head
	delete timeline->next;
}
