// Minesweeper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Board.h"
#include "Player.h"

int main()
{
	int num = 0;

	Player player1;  //create an instance of player, this creates an instance of board

	cout << "How many bombs would you like to be placed?\n";
	cin >> num;

	player1.generateBombs(num);
	player1.drawBoard();

	player1.playerTurn();

	while (1)
	{
	}
    return 0;
}

