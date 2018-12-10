/*

Q2– String of characters as arranged in a cellphone i.e.
1- NULL
2-a,b,c
3-d,e,f
4-g,h,i
5-j,k,l
6-m,n,o,p
7-q,r,s
8-t,u,v
9-w,x,y,z
0-NULL

Print all combinations for given number of digits(k) in lexicographical order .
Constraint : 1 <= k < 4
For Example : Input = 234
Output : adg adh adi aeg aeh aei afg afh afi 
		 bdg bdh bdi beg beh bei bfg bfh bfi 
		 cdg cdh cdi ceg che dei cfg cfh cfi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIGITS 10
#define MAX_ALPHA_CHARS 4
#define LETTERS 3

char **create_cellphone(char **cellphone)
{
	int i;

	cellphone = malloc(DIGITS * sizeof(char*));

	for (i = 0; i < DIGITS; i++)
	{
		cellphone[i] = malloc((MAX_ALPHA_CHARS + 1) * sizeof(char));
	}

	return cellphone;
}

char **build_cellphone(char **cellphone)
{
	int i;

	strcpy(cellphone[1], "");
	strcpy(cellphone[0], "");
	strcpy(cellphone[2], "abc");
	strcpy(cellphone[3], "def");
	strcpy(cellphone[4], "ghi");
	strcpy(cellphone[5], "jkl");
	strcpy(cellphone[6], "mnop");
	strcpy(cellphone[7], "qrs");
	strcpy(cellphone[8], "tuv");
	strcpy(cellphone[9], "wxyz");

	return cellphone;
}

int main(void)
{
	int input = 0;
	int l = 0;
	char *temp = malloc((LETTERS + 1) * sizeof(char)); 
	char **cellphone;

	printf("Input: ");
	scanf("%d", &input);

	cellphone = create_cellphone(cellphone);
	cellphone = build_cellphone(cellphone);

	for (int i = 0; cellphone[input / 100][i] != '\0'; i++)
	{
		temp[l++] = cellphone[input / 100][i];

		for (int j = 0; cellphone[(input % 100) / 10][j] != '\0'; j++)
		{
			temp[l++] = cellphone[(input % 100) / 10][j];

			for (int k = 0; cellphone[(input % 10)][k] != '\0'; k++)
			{
				temp[l] = cellphone[(input % 10)][k];
				printf("%s\n", temp);
			}
			
			l--;
		}

		l = 0;
	}


	return 0;
}

