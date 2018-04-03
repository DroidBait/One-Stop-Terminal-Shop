#include <stdio.h>
#include <stdlib.h>

void printmenu();
void vselection(int selection);

int main(int argc, char *argv[])
{
  int selection = 0;
  //std::vector<string> List;

  printmenu();

  printf("Please make a selection\n");
  scanf("%i", &selection);

  vselection(selection);

  return 0;
}

void printmenu()
{
  printf( "1. First\n" );
  printf( "2. Second\n" );
  printf( "3. Third\n" );
  printf( "4. Close\n" );
}

void vselection(int selection)
{
  if (selection == 4)
  {
    exit(0);
  }
}
