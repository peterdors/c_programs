// Peter Dorsaneo
// ==============
// dups.c
// ======
// Creates array of duplicating ints, and attempts to print out the array
// but without printing the duplicates in the array more than once.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_LENGTH 10
#define RAND_NUMBER_SIZE 5


// creates an array containing duplicates
// utilizes the random number generator and modulus operator for generating random numbers
// from 0 to RAND_NUMBER_SIZE
int *create_array_of_duplicates(int len)
{
	int i, *array;

	array = malloc(sizeof(int) * len);

	srand(time(NULL));

	for (i = 0; i < len/2; i++)
	{
		array[i] = rand() % RAND_NUMBER_SIZE;
	}

	for (i = len/2; i < len; i++)
	{
		array[i] = rand() % RAND_NUMBER_SIZE;
	}

	return array;
}

// prints the given array
void print_array(int *array, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

// frees dynamically allocated memory in the array
void destroy_array(int *array)
{
	free(array);
}

// checks to see if the value is duplicated in the array
// only needs to find one duplicate to return true (1)
// otherwise will return false (0)
int is_duplicated(int value, int *array, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (value == array[i])
			return 1;
	}

	return 0;
}

// function to print the elements in an array, but also does not print duplicating elements
void print_non_duplicates_in_array(int *array, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		if(is_duplicated(array[i], array, i))
		{
			continue;
		}

		printf("%d ", array[i]);
	}

	printf("\n");
}

// get things going
int main(void)
{
	int *array = create_array_of_duplicates(BUFFER_LENGTH);

	// checks that array memory was successfully allocated using malloc 
	// in our create_array_of_duplicates function 
	// returns 1 for signaling an error occurred in our main function
	if (array == NULL)
	{
		printf("array is not allocated\n");
		return 1;
	}

	// first print array to show the duplicating numbers
	print_array(array, BUFFER_LENGTH);

	// then print the array again, excluding numbers if they are duplicates
	print_non_duplicates_in_array(array, BUFFER_LENGTH);

	// free the array
	destroy_array(array);

	return 0;
}
