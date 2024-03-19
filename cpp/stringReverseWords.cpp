#include <iostream>
#include <cstring>
using namespace std;

const int MAX_STRING_LENGTH = 10000;

int main() 
{
    char s[MAX_STRING_LENGTH];
    int lastSepIndex;
    
    cin.getline(s, MAX_STRING_LENGTH);

    lastSepIndex = strlen(s);

    for(int i = lastSepIndex - 1; i >= 0; i--) {
        if(s[i - 1] == ' ' || i == 0) {
            for(int j = i; j < lastSepIndex; j++) {
                if(s[j] != ' ')
                    cout << s[j];
            }
            
            cout << " ";
            
            lastSepIndex = i - 1;
        }
    }

    return 0;
}
