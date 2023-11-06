#include <stdio.h>
#include <stdbool.h>
#define size 3

void printBoard (char board[][3])
{
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			printf("|");
			printf("%c", board[row][col]);
		}
		printf("\n");
	}
}

bool checkWin(char board[][size], char player)
{
	// if there is a winner along the horizontal
	for (int row = 0; row < size; row++)
	{
		char checker = player;
		for (int col = 0; col < size; col++)
		{
			if (checker != board[row][col])
				break;
			if (col == size - 1)
				return true;
		}
	}

	// if there is a winner along the vertical
	for (int row = 0; row < size; row++)
	{
		char checker = player;
		for (int col = 0; col < size; col++)
		{
			if (checker != board[col][row])
				break;
			if (col == size - 1)
				return true;
		}
	}

	// if there is winner along the diagonal
	char checker =  player;
	for (int row = 0; row  < size; row++)
	{
		if (checker != board[row][row])
			break;
		if (row == size - 1)
			return true;
	}
	return false;
}

bool checkFull (char board[][size])
{
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			if (board[row][col] == ' ')
				return false;
		}
	}
	return true;
}
int main ()
{
	char board[size][size];
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			board[row][col] = ' ';
		}
	}

	bool game = true;
	char player = 'X';
	int r = 0;
	int c = 0;
	while (game)
	{
		printf("Input the r and c: ");
		scanf("%d", &r);
		scanf("%d", &c);

		if (board[r][c] == ' ')
		{
			board[r][c] = player;
			bool win = checkWin(board, player);
			if (win)
			{
				printf("Player %c has won\n", player);
				game = false;
			}

			bool full = checkFull(board);

			if (full)
			{
				printf("The game end in draw\n");
				game = false;
			}

			if (player == 'X')
				player = 'O';
			else
				player = 'X';
			printBoard(board);
		}
		else
		{
			printf("This position is filled already, try another position.\n");
			printBoard(board);
		}
	}
}
