#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	Board board;

}


Player::~Player()
{
}

void Player::playerTurn()
{
	int x, y = 0; //store x and y location entered by user
	printf("Please select a X location (left to right)\n");
	cin >> x;
	printf("Please select a Y location (up and down)\n");
	cin >> y;

	if (values[y][x] == 10)  //I accidentally made x and y the wrong way round
	{
		cout << "That was a bomb. Game Over\n";
	}
	else
	{
		Player::uncoverSquares(x, y);
	}
}

int Player::uncoverSquares(int x, int y)
{

}