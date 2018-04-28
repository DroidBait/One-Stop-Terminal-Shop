#pragma once

#include <vector>
#include <iostream>

using namespace std;

class Board
{
public:
	Board();
	~Board();
	int values[12][12]; //stores values for amount of nearby mines
	int grid[12][12]; //stores the values which need to be shown to the user
	vector<int> addX; //store X values for recursive algorithm
	vector<int> addY; //store Y values for recursive algorithm
	void drawBoard();
	void generateBombs(int number); //Function that places the number of bombs specified by the user

private:
	void createBlanks(); //fill the board that will be displayed to the user with blanks and put a 0 in all spaces for values
	void uncoverSquares(int x, int y); //check adjecent squares, if incovered and not a bomb, uncover and add to queue

};

