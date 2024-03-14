#include <iostream>
using namespace std;

const int MAX_STRING_LENGTH = 10000;

int main()
{
    //write your code here
    char s[MAX_STRING_LENGTH];
    char replace;
    char with;
    
    cin.getline(s, MAX_STRING_LENGTH);
    cin.clear();
    cin.get(replace);
    cin >> with;
    
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == replace)
            s[i] = with;
    }
    
    //write out the modified string
    cout << s;

    return 0;
}
