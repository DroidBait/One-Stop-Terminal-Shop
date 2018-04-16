#pragma once

#include "Board.h"
#include <iostream>
using namespace std;

class Player : public Board
{
public:
	Player();
	~Player();

	void playerTurn(); //function that controls what happens when a player selects a square

private:
	int uncoverSquares(int x, int y);

};

