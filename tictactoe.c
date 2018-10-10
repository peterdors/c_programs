#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
// COLUMNS is set to include enough chars for the terminating char as well.
#define COLUMNS 12

char **create_board()
{
	char **temp;
	int i;

	temp = malloc(sizeof(char *) * ROWS);

	for (i = 0; i < ROWS; ++i)
	{
		temp[i] = malloc(sizeof(char) * COLUMNS);
	}
	strcpy(temp[0], " 1 | 2 | 3 ");
	strcpy(temp[1], "-----------");
	strcpy(temp[2], " 4 | 5 | 6 ");
	strcpy(temp[3], "-----------");
	strcpy(temp[4], " 7 | 8 | 9 ");

	return temp;
}


void display_board(char **board)
{
	int i;

	for (i = 0; i < ROWS; i++)
	{
		printf("%s\n", board[i]);
	}
}

void update_board(char **board, int *count, int move)
{
	int i, j;

	for (i = 0; i < ROWS; i += 2)
	{
		for (j = 0; j < COLUMNS; ++j)
		{
			if(board[i][j] - '0' == move)
			{
				board[i][j] = (*count % 2 == 0 ? 'X' : 'O');
				break;
			}
		}
	}
}

int check_board(char **board)
{

	int i, j;

	// checks for horizontal sequence
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

	// checks for vertical sequence
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

	if(
		 board[0][1] == board[2][5] &&
		 board[0][1] == board[4][9] &&
		 board[2][5] == board[4][9]
		)
	{
		return 1;
	}

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

int main(void)
{	
	int i, j, move = -1, count = 0;
	char **board = create_board();

	display_board(board);

	printf("Player 1 is X\nPlayer 2 is O\n");

	// enter 0 as input for scanf() to terminate the loop
	while (check_board(board) == 0)
	{
		printf("Player %d enter a number to make a move: ", count % 2 == 0 ? 1 : 2);
		scanf("%d", &move);

		update_board(board, &count, move);

		display_board(board);

		count++;
	}

	printf("The winner is Player %s\n", (count+1) % 2 == 0 ? "1 (X)" : "2 (O)");

	destroy_board(board);
	return 0;
}
