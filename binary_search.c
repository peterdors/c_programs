#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// Recursive solution for binary search algorithm.
// Returns the index of the given (val)ue in the array
int binarySearch(int array[], int l, int r, int val)
{

	int mid = l + (r - l) / 2 ;

	if (r >= l)
	{
		if (array[mid] == val)
		{
			return mid;
		}
		else if (array[mid] < val)
		{
			return binarySearch(array, mid + 1, r, val);
		}
		else if (array[mid] > val)
		// else
		{
			return binarySearch(array, l, mid - 1, val);
		}
	}

	return -1;
}

// int binarySearchHelper(int *array, );




int main(void)
{
	int valueLookingFor = 2;
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int retval = -1;
	retval = binarySearch(array, 0, SIZE - 1, valueLookingFor);

	printf("Value %d found at index %d\n", valueLookingFor, retval);

	return 0;
}
