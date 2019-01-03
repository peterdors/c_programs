// Peter Dorsaneo
//
// tictactoe.c
// ===========
// Simple program for playing tic-tac-toe with another person (2 player game).
// 
// To compile: 
// 1). Open terminal and cd into the file directory. 
// 2). Make the following call "gcc tictactoe.c"
// 3). Then call "./a.out"
// 4). Play tictactoe.c!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 
#define ROWS 5
// COLUMNS is set to include enough chars for the terminating char as well.
#define COLUMNS 12

// Function to build the 2d array of the game board. 
char **create_board()
{
	char **board;
	int i;
	// Allocate memory for the board char array.
	board = malloc(sizeof(char *) * ROWS);

	for (i = 0; i < ROWS; ++i)
	{
		board[i] = malloc(sizeof(char) * COLUMNS);
	}
	// Copy the board diagram over to the array.
	strcpy(board[0], " 1 | 2 | 3 ");
	strcpy(board[1], "-----------");
	strcpy(board[2], " 4 | 5 | 6 ");
	strcpy(board[3], "-----------");
	strcpy(board[4], " 7 | 8 | 9 ");

	return board;
}

// Function for printing out the board each move. 
void display_board(char **board)
{
	int i;

	for (i = 0; i < ROWS; i++)
	{
		printf("%s\n", board[i]);
	}
}

// Function for updating the board when a player makes a move. 
void update_board(char **board, int *player, int move)
{
	int i, j;

	for (i = 0; i < ROWS; i += 2)
	{
		for (j = 0; j < COLUMNS; ++j)
		{
			if(board[i][j] - '0' == move)
			{
				board[i][j] = (*player % 2 == 0 ? 'X' : 'O');
				break;
			}
		}
	}
}

// Checks the board to see if there is a winning sequence on the board.
// Returns 1 if there is a winner, and 0 otherwise.
int is_winning_move(char **board)
{
	int i;

	// Checks for horizontal sequence.
	for (i = 0; i < ROWS; i += 2)
	{
		
		if (
			 board[i][1] == board[i][5] &&
			 board[i][1] == board[i][9] &&
			 board[i][5] == board[i][9]
			)
		{
			return 1;
		}
	}

	// Checks for vertical sequence.
	for (i = 1; i < COLUMNS; i += 4)
	{
		if (
			 board[0][i] == board[2][i] &&
			 board[0][i] == board[4][i] &&
			 board[2][i] == board[4][i]
			)
		{
			return 1;
		}
	}

	// Checks for diagonal sequence from topmost left to right.
	if(
		 board[0][1] == board[2][5] &&
		 board[0][1] == board[4][9] &&
		 board[2][5] == board[4][9]
		)
	{
		return 1;
	}
	// Checks for diagonal sequence from topmost right to left.
	if(
		 board[0][9] == board[2][5] &&
		 board[0][9] == board[4][1] &&
		 board[2][5] == board[4][1]
		)
	{
		return 1;
	}

	return 0;
}

void destroy_board(char **board)
{
	int i, j;

	for(i = 0; i < ROWS; i++)
	{
		free(board[i]);
	}

	free(board);
}
// Function for checking if move already has been made. 
// Returns 1 if true, 0 otherwise.
int is_move_already_made(int *moves_made, int move)
{
	int x = moves_made[move-1];
	if (x)
	{
		printf("%d\n", x);
		return 1;
	}
	else
		return 0;
}

void play_game(void)
{
	int i, j, move = -1, player = 0, flag = 0, retval = -1;
	char **board = create_board();
	int *moves_made = calloc(sizeof(int), 9);

	display_board(board);

	printf("Player 1 is X\nPlayer 2 is O\n");

	// Loops until there is a winner, 
	// or if no winner then terminates when player variable 
	// is greater or equal to 10.
	while ( 1 )
	{
		printf("Player %d, enter a number to make a move: ", player % 2 == 0 ? 1 : 2);
		scanf("%d", &move);
		// Don't let the player enter a bad move.
		if (is_move_already_made(moves_made, move))
		{
			printf("Can't move there! Try another spot.\n");
			continue;
		}
		// Mark this move if spot not already taken.	
		moves_made[move - 1] = move;

		update_board(board, &player, move);

		display_board(board);
		// Next player, as determined by even or odd numbers.
		player++;
		// Check if there's a winner.
		retval = is_winning_move(board);

		// Loop terminating condition. 
		if (retval == 0 && player >= 9)
		{
			flag = 1;
			break;
		}
		else if (retval == 1)
		{
			break;
		}
	}
	// Determine whether there's a winner, or a tie in the game.
	if (flag)
	{
		printf("There is no winner in this game...\n");
	}
	else
	{
		printf("The winner is Player %s\n", (player+1) % 2 == 0 ? "1 (X)" : "2 (O)");
	}
	// Clean up allocated memory.
	destroy_board(board);
	free(moves_made);
	
}

int main(void)
{	
	play_game();
	return 0;
}
