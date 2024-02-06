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
    result = 0;          // set result to 0, even occurence
    
    // get input until -1
    cin >> temp;
    arrMin = temp;
    arrMax = temp;
    for(count = 0; temp != ENDOFLIST; count++) {
        array[count] = temp;
        cin >> temp;
    }
    
    // find min and max values in array
    for(int i = 0; i < count; i++) {
        if(array[i] < arrMin) {
            arrMin = array[i];
        }
        if(array[i] > arrMax) {
            arrMax = array[i];
        }
    }
    
    // if length of array is 1, set result to 1
    if(count == 1) {
        result = 1;
    }
    
    // for all values in array, or until result is 1
    for(int j = 0; result != 1 && j < count; j++) {
        // check occurence of min array value to max array value
        for(int curr = arrMin; curr < arrMax; curr++) {
            // add 1 to result if current value checking
            if(array[j] == curr) {
                result++;
            }
        }
        
        // even or odd occurence
        result %= 2;
    }   
    // End of your code

    cout << result;
}
