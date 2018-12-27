#include <stdio.h>
#include <stdlib.h>

int *initBoard(int *board, int n)
{
	board = calloc(sizeof(int), n);

	for (int i = 0; i < n; i++)
	{
		board[i] = -1;
	}
	
	return board;
}

void solveNQueens(int n)
{
	// Does the initializing of setting each element to -1 for us. 
	int *board  = initBoard(board, n);

	/*
	Each index in board array is the row,
	with each value held at the index indicating 
	the column the queen is to be placed.
		-----------------
		|	|	|	|	|
		-----------------
		|	|	|	|	|
		-----------------
		|	|	|	|	|
		-----------------
		|	|	|	|	|
		-----------------

	*/

	solveBoard(board, start, n);
}

// @params: the array for the board, the starting row/index on the board
// 			and the size of the board. 
void solveBoard(int *board, int start, int n)
{
	int position, i, j; 
	int queen_position[start];

	// Base case.
	if 	(
			start == n
		)
	{
		return;
	}

	for (i = 0; i < start; i++)
	{
		for (j = 0; j < n; j++)
		{
			// Check if the board has a queen placed at position j.
			// Remember that position board[start] is the starting row
			// to place a queen at.
			if (!isConflict(board, start, i, j, n))
			{
				// Check if there is a conflict with placing that queen.

			}
		}
	}

	
}


int isConflict(int *board, int start, int i, int j, int n)
{

	

}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage: ./a.out <number>\n");
		exit(1);
	}

	solveNQueens(atoi(argv[1]));


	return 0;
}