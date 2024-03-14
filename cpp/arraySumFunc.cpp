long sumArray(int *array, int size)
{
    long sum = 0;
    
    for(int i = 0; i < size; i++)
        sum += array[i];
    
    return sum;
}
