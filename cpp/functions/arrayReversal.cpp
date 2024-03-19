void reverseCopy(int source[], int destination[], int size)
{   
    int dupe[size];
    
    for(int i = 0; i < size; i++)
        dupe[i] = source[i];
    
    for(int j = 0; j <= size; j++)
        destination[j] = dupe[size - j - 1];
}
