// Author: Edgar Han
// Version: 20160904
// Takes in an array of positive int and returns the
// second largest value of the array.
// This was a career fair coding challenge

#include <stdio.h>

/*
	Use a variable to hold the largest.
*/
int secondLargest(int * array, int length) {
	int first = array[0];
	int second = first;

	// first check for largest and set the variable.
	for (int i = 1; i < length; i++)
	{
		if (array[i] > first)
		{
			first = array[i];
		}
	}

    // next look for second largest.
    for( int i = 1; i < length; i++ )
    {
    	if (array[i] > second && array[i] < first)
    	{
    		second = array[i];
    	}
    }
    return second;
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
	printf("Second Largest Value: %d\n", secondLargest(theArray, 10));
	return 0;
}