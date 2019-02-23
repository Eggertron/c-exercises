// Author: Edgar Han
// Version: 20160904
// Takes in an array of int and outputs
// the array with zeroes moved to the towards the
// lower index.
// This was a technical interview question that I
// was given

#include <stdio.h>

/*
	Starts from the end of the array and moves all
	numbers back according to zeroes counted
	counter keeps track of num of zeroes.
	The passed array will be modified.
*/
void arrayZeroSorting(int * array, int length) {
	int counter = 0;	// counter for zeroes.
    for( int i = length - 1; i >= 0; i-- )
    {
    	if (array[i] == 0)
    	{
    		counter++;
    	}
    	else
    	{
    		array[i + counter] = array[i];
    		array[i] = 0;
    	}
    }
}

void printArray(int * array, int length) {
	printf("[");
	for (int i = 0; i < length; i++)
	{
		fprintf(stdout, "%d", array[i]);
		if (i + 1 < length)
		{
			printf(", ");
		}
	}
	printf("]\n");
}

int main() {
	int theArray[] = {2, 4, 6, 0, 5, 0, 12, 0, 0, 0};
	printArray(theArray, 10);
	arrayZeroSorting(theArray, 10);
	printArray(theArray, 10);
	return 0;
}