#include <stdio.h>
#include <stdlib.h>
#define BUFFER 64


// function that takes a source string and copies it to the destination string
// caveat is it will also return the length of the string copied if you need that as well
//
// and takes care of the null terminating string in case destination is already a string,
// that is longer than source string
int copy_string(char *source, char *destination)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}

	destination[i] = '\0';

	return ++i;
}



// get command line input for string and copy it to another string instance
// catch: don't use string.h library functions
int main(int argc, char **argv)
{
	char source[BUFFER];
	char destination[BUFFER];
	int n;

	if (argc < 2)
	{
		printf("Error with command line inputs\n");
		return 1;
	}

	// testing for destination string that is longer than copied string
	copy_string("al;djfl;flasjflksjdlfkjsdl;fjs;ldfjls", destination);

	n = copy_string(argv[1], source);

	copy_string(source, destination);

	printf("Length of string: %d \n\t(includes null terminating char)\n", n);
	printf("String copied: %s\n", destination);

	return 0;
}
