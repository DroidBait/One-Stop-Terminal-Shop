//Compile useing gcc Menu.c -o menu -lncurses

#include <stdio.h>
#include <ncurses.h>

int main()
{
  initscr();   //start curses mode
  printw("Testing"); //print Testing
  refresh();  //print it to the screen
  getch();  //wait for user input
  endwin(); //end curses mode

  return 0;
}
