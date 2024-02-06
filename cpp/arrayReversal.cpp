/* 
  This program reverses the values of a given array

  Author: Braxton Worsley
*/

#include<iostream>
using namespace std;

const int MAXSIZE = 20;
const int ENDOFLIST = -1;

//Your program will be evaluated by this main method and several test cases.
int main()
{
    int array[MAXSIZE];    // Array to hold the number list
    int count;             // Number of elements in the array    

    // Start of your code
    int temp;
    
    // get values for array until -1
    cin >> temp;
    for(count = 0; temp != ENDOFLIST; count++) {
        array[count] = temp;
        cin >> temp;
    }
    
    // duplicate array
    int arrayDupe[MAXSIZE];
    for(int i = 0; i < count; i++) {
        arrayDupe[i] = array[i];
    }
    
    // reverse array
    for(int j = 0; j <= count; j++) {
        array[j] = arrayDupe[count - j - 1];
    }
    // End of your code

    // Prints the array to the screen    
    for (int x = 0; x < count; x++)
    {
        cout << array[x] << " ";
    }

}
