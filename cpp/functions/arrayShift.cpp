void replaceElements(int array[], int size)
{
    for(int i = size; i > 0; i--)
        array[i] = array[i - 1];
    array[0] = -1;
}
