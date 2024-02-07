/*
    This program takes input of integers, stopping when given -1
    It then checks the occurence of each different number of the array
    If the occurence is even, it returns 0; odd, returns 1

    Author: Braxton Worsley
*/

#include<iostream>
using namespace std;

const int MAXSIZE = 10000;
const int ENDOFLIST = -1;

//Your program will be evaluated by this main method and several test cases.
int main()
{
    int result = -5;
    
    // Start of your code
    int temp;            // input value
    int count;           // length of array
    int array[MAXSIZE];  // array initialization
    int arrMin;          // min value in array
    int arrMax;          // max value in array
    int occur;           // occurence count
    
    // get initial input; set to min and max
    // get input until -1
    cin >> temp;
    arrMin = temp;
    arrMax = temp;
    for(count = 0; temp != ENDOFLIST; count++) {
        // find min and max values in array
        if(temp < arrMin) {
            arrMin = temp;
        }
        if(temp > arrMax) {
            arrMax = temp;
        }

        array[count] = temp;
        cin >> temp;
    }
    
    // if length of array is 1, set result to 1
    if(count == 1) {
        result = 1;
    }
    
    // check occurrence of min array value to max array value
    for(int curr = arrMin; result != 1 && curr <= arrMax; curr++) {
        // check all array values for current value to check
        for(int j = 0; j < count; j++) {
            if(array[j] == curr) {
                occur++;
            }
        }
        result = occur % 2;
    }
    // End of your code

    cout << result;
}
