#include <stdio.h>
#include <stdlib.h>
#define SIZE 14

/*

Q1– Given an array of numbers, 
	arrange them in an alternate fashion such that every number is followed by a number of opposite sign. 

	Also the order was to be maintained. 
	
	If the count of negative numbers is more keep the extra at last in array and same for positive numbers.

Example :
Input: -3 -2 6 0 7 -1 -8
Output: -3 6 -2 0 -1 7 -8
*/

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp; 
}

int *arrange_array(int size, int *array)
{
	int i, j, k;

	for (i = 0; i < size; i += 1)
	{
		// Check for a negative element.
		if (array[i] < 0)
		{
			// Want the next one to be positive.
			if (array[i+1] >= 0)
			{
				continue;
			}
			// Otherwise find the closest positive one
			// and swap it with the i+1 index.
			else
			{
				// Loop until we find a negative element.
				j = k = i + 1;
				while (array[j] < 0 && j < SIZE)
				{
					j++;
				}

				if (j < SIZE)
				{
					// Swap once we find our negative.
					swap(&array[j], &array[k]);
				}
			}
		}
		else
		{
			// Otherwise we have a positive element.
			if (array[i+1] < 0)
			{
				continue;
			}
			else
			{
				// Loop until we find a non-negative element.
				j = k = i + 1;
				while (array[j] >= 0 && j < SIZE)
				{
					j++;
				}

				if (j < SIZE)
				{
					// Swap once we find our negative.
					swap(&array[j], &array[k]);
				}
			}
		}
	}

	return array;
}


void print_array(int size, int *array)
{
	int i; 

	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(void)
{
	int arr1[SIZE] = {-3 ,-2, 6 ,0 ,7, -1 ,-8, -10, 9, 3, -3, 2, 2, 2 };
	// int arr1[SIZE] = {-3, -2, 6, 0, 7, -1, -8};
	int *array = malloc(sizeof(int) * SIZE);
	int i;

	for (i = 0; i < SIZE; i++)
	{
		array[i] = arr1[i];
	}

	print_array(SIZE, array);

	array = arrange_array(SIZE, array);

	print_array(SIZE, array);

	free(array);

	return 0;
}
