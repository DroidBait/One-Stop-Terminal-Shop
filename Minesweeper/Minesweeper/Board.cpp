#include "stdafx.h"
#include "Board.h"


Board::Board()
{
	createBlanks();
}


Board::~Board()
{
}

void Board::drawBoard()
{
	//print out grid to screen
	printf("|0|1|2|3|4|5|6|7|8|9|X\n");

	for (int a = 1; a < 11; a++)
	{
		printf("+-+-+-+-+-+-+-+-+-+-+\n");
		for (int b = 0; b < 10; b++)
		{
			if (Board::values[a][b] == 10)
			{
				printf("|%c", grid[a][b]);
			}
			else
			{
				//printf("|%i", values[a][b]);
				printf("|%c", Board::grid[a][b]);
			}
		}
		printf("| %d\n", a);
	}
	printf("                      Y\n");
}

void Board::createBlanks()
{
	//apply a blank character to all squares in the grid
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			Board::grid[i][j] = ' ';
		}
	}

	//apply value 0 to all squares
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			Board::values[i][j] = 0;
		}
	}
}

void Board::generateBombs(int number)
{
	for (int i = 0; i < number; i++)
	{
		int x, y = 0; //store random number locations
		x = rand() % 10;
		y = rand() % 10;

		if (values[x][y] == 0 && x > 0 && x < 12 && y > 0 && y < 12) //check if square currently has a bomb and is inside the playing area
		{
			values[x][y] = 10; //make value 10 to signify a bomb							   
		}
		else
		{
			i -= 1; //take one from i to repeat the process
		}
	}
}