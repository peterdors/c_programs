// Peter Dorsaneo
// 
// n_queens.c
// ==========
// Backtracking solution to the N-Queens problem. Finds number of ways to arrange
// N number of Queens on an NxN chess board such that no other queen can attack
// on another, and prints out the solution.  

#include <stdio.h>
#include <stdlib.h>

int *initBoard(int *board, int n);
void solveBoard(int *board, int start, int n);
int allQueensAreSafe(int *board, int curr_col);
void printBoard(int *board, int n);
void solveNQueens(int n);

// Main driver function, handling command line arguments as input. 
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

// Backtracking function to call for solving the N Queens problem.
// @params: The array for the board, 
//			the starting curr_col/index on the board,
// 			and the size of the board. 
void solveBoard(int *board, int curr_col, int n)
{
	int curr_row;
	// If we have found a solution, then print it out and return.
	if (curr_col == n)
	{
		printBoard(board, n);
		return;
	}
	
	// Keep trying to solve the board. 
	for (curr_row = 0; curr_row < n; curr_row++)
	{	
		// Try to place a queen in the current row. 
		board[curr_col] = curr_row;

		if (allQueensAreSafe(board, curr_col))
		{
			solveBoard(board, curr_col + 1, n);
		}

		// We don't have to undo anything here, since we will keep trying each 
		// next curr_row within our for-loop 
	}
}


// Function for checking the position we are trying to place a queen. 
// Returns 0 if we can not safely place a queen, 1 otherwise.
// We can not place a queen if there is one already on the same
// row, or if there is diagonally adjacent to the queen we are placing. 
//
// @params: The board array to hold the row elements for each column indice,
// 			the current column we are looking to place a queen at.
int allQueensAreSafe(int *board, int curr_col)
{
	int i; 

	for (i = 0; i < curr_col; i++)
	{
		if 	(
				board[i] == board[curr_col] ||
				(abs(board[i] - board[curr_col]) == (curr_col - i))
			)
		{
			return 0;
		}
	}

	return 1;
}

// Function to print out the solution to the board, 
// if we have found one. 
// @params: The board array, 
// 			the NxN board size.
void printBoard(int *board, int n)
{
	int row, col;

	printf("Here is a solution:\n");

	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n; col++)
		{
			if (board[col] == row)
			{
				printf("Q ");
			}
			else
			{
				printf("_ ");
			}
		}

		printf("\n");
	}
}

// Function for intializing the board array and  
// calling the solveBoard backtracking function
// @params: The NxN board size.
void solveNQueens(int n)
{
	// Does the initializing of setting each element to -1 for us. 
	int *board  = initBoard(board, n);

	/*
	Each index in board array is the curr_row,
	with each value held at the index indicating 
	the column the queen is to be placed.
		-----------------
		|	| Q |	|	|
		-----------------
		| Q |	|	|	|
		-----------------
		|	|	|	| Q |
		-----------------
		|	| Q |	|	|
		-----------------

	*/

	solveBoard(board, 0, n);
}


// Function to create the board and initialize all its values to -1.
// @params: The board array, 
// 			the NxN board size.
int *initBoard(int *board, int n)
{
	board = calloc(sizeof(int), n);

	for (int i = 0; i < n; i++)
	{
		board[i] = -1;
	}
	
	return board;
}

