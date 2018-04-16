#include <stdio.h>
#include <stdlib.h>

void drawBoard();  //draw the board
char grid[10][10];
int values[10][10];
char addToChar(char input); //Function to add 1 to a numner stored as a char
void createBlanks(); //adds a blank character to all squares for when the board gets printed
void fillZero(); //fill values with 0
void generateBombs(int number);  //randomly place bomb locations
int numBombs = 0; //store how many bombs to create
int bombsFound = 0; //store number of bombs found
void playerTurn();
void generateNumbers(); //Generate the numbers that tell the player where bombs are
void placeNumbers(int x, int y); //places the values around the bomb
void uncoverSquares(int x, int y); //a function to uncover surronding squares from player selection

int main()
{
  createBlanks();
  fillZero();
  printf("How many bombs would you like to add?\n");
  scanf("%d", &numBombs);
  generateBombs(numBombs);
  generateNumbers();
  drawBoard();
  playerTurn();
  drawBoard();
  printf("END\n");
}

void drawBoard()
{
  //print out grid to screen
  printf("|0|1|2|3|4|5|6|7|8|9|X\n");

  for (int a = 0; a < 10; a++)
  {
    printf("+-+-+-+-+-+-+-+-+-+-+\n");
    for (int b = 0; b < 10; b++)
    {
      if (values[a][b] == 10)
      {
        printf("|%c", grid[a][b]);
      }
      else
      {
        //printf("|%i", values[a][b]);
        printf("|%c", grid[a][b]);
      }
    }
    printf("| %d\n", a);
  }
  printf("                      Y\n");
}

void createBlanks()
{
  //apply a blank character to all squares in the grid
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      grid[i][j] = ' ';
    }
  }
}

void fillZero()
{
  //apply value 0 to all squares
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      values[i][j] = 0;
    }
  }
}

void generateBombs(int number)
{
  for (int i = 0; i < number; i++)
  {
    int x, y = 0; //store random number locations
    x = rand() % 10;
    y = rand() % 10;

    if (values[x][y] == 0) //check if square currently has a bomb
    {
      values[x][y] = 10; //make value 10 to signify a bomb
      //grid[x][y] = 'B'; //remove for final version of game.
    }
    else
    {
      i -= 1; //take one from i to repeat the process
    }
  }
}

void playerTurn()
{
  int x, y = 0; //store x and y location entered by user
  printf("Please select a X location (left to right)\n");
  scanf("%d", &x);
  printf("Please select a Y location (up and down)\n");
  scanf("%d", &y);

  if (values[y][x] == 10)  //I accidentally made x and y the wrong way round :s somehow?
  {
    printf("That was a bomb. Game Over\n");
    exit(0);
  }
  else
  {
    uncoverSquares(x,y);
  }
}

char addToChar(char input)
{
  //if char == 0, then return 1
  if (input == '0')
  {
    return '1';
  }

  if (input == '1')
  {
    return '2';
  }

  if (input == '2')
  {
    return '3';
  }

  if (input == '3')
  {
    return '4';
  }

  if (input == '4')
  {
    return '5';
  }

  if (input == '5')
  {
    return '6';
  }

  if (input == '6')
  {
    return '7';
  }

  if (input == '7')
  {
    return '8';
  }

  if (input == '8')
  {
    return '9';
  }

}

void generateNumbers()
{
  //scan for a bomb
  //add one to the value of the 8 boxes around the bomb
  for (int y = 0; y < 10; y++)
  {
    for (int z = 0; z < 10; z++)
    {
      if (values[y][z] == 10)
      {
        placeNumbers(y, z);
      }
    }
  }

}

void placeNumbers(int y, int z)
{
  if (values[y-1][z-1] != 10)
  {
    values[y-1][z-1] += 1;
  } 

  if (values[y-1][z] != 10)
  { 
    values[y-1][z] += 1;
  }
  
  if (values[y-1][z+1] != 10)
  { 
    values[y-1][z+1] += 1;
  }  

  if (values[y][z-1] != 10)
  {
    values[y][z-1] += 1;
  }

  if (values[y][z+1] != 10)
  {
    values[y][z+1] += 1;
  }  

  if (values[y+1][z-1] != 10)
  {
    values[y+1][z-1] += 1;
  }

  if (values[y+1][z] != 10)
  {
  values[y+1][z] += 1;
  }

  if (values[y+1][z+1] != 10)
  {  
    values[y+1][z+1] += 1;
  }
}

void uncoverSquares(int x, int y)
{
  int squareLocationx[100]; //store location of centre square
  int squareLocationy[100]; //store the y locatin of current square
  int currentArrayPosition = 0;
  
  squareLocationx[currentArrayPosition] = x; //store location player imput as first square
  squareLocationy[currentArrayPosition] = y;
  
  
}

bool checkAdjecent(int x, int y) //function to check to see if the surrounding 8 squares are empty
{
  int bombsFound = 0;

  if (x - 1 >= 0 && x - 1 <= 9)
  {
    
  }
}
