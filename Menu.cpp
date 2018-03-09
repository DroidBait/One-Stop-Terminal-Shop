//Compile useing gcc Menu.c -o menu -lncurses
//With help from tutorials on https://rhardih.io/2010/04/using-ncurses-in-c-for-text-user-interfaces-featuring-xcode/
//http://techlister.com/linux/creating-menu-with-ncurses-in-c/1293/

//#include <iostream>
#include <stdio.h>
#include <ncurses.h>
//#include <cstdlib>

#define WORLD_HEIGHT 20
#define WORLD_WIDTH 50

void loadSelection(int s);  //function to get selection and use a switch statement to load
bool open = TRUE;  //controls program being left open or closed

int main(int argc, char *argv[])
{
  do {
  WINDOW *terminal_shop;
  int offsetx, offsety, ch;
  char list[5][7] = { "one", "two", "Three", "Four", "Close" };
  char item[7];

  initscr();   //start curses mode
  //printw("Testing"); //print Testing
  refresh();  //print it to the screen

  offsetx = (COLS - WORLD_WIDTH) / 2;
  offsety = (LINES - WORLD_HEIGHT) / 2;

  terminal_shop = newwin(WORLD_HEIGHT, WORLD_WIDTH, offsety, offsetx);

  box(terminal_shop, 0, 0);

  for (int i = 0; i < 5; i++) //print out all of the items in the list
  {
    if (i==0)
    {
      wattron(terminal_shop, A_STANDOUT); //highlight the first item
    }
    else
    {
      wattroff(terminal_shop, A_STANDOUT);
    }
    sprintf(item, "%-7s", list[i]);
    mvwprintw(terminal_shop, i+1, 2, "%s", item);
  }

  wrefresh(terminal_shop); //update the screen

  int i = 0;
  //char ch;
  noecho(); //disable characters printing to screen
  keypad(terminal_shop, TRUE); //enable keyboard support
  curs_set(0); //hide the default cursor

  //get input
  while((ch = wgetch(terminal_shop)) != 'q')
  {
      // right pad with spaces to make the items appear with even width.
      sprintf(item, "%-7s",  list[i]);
      mvwprintw(terminal_shop, i+1, 2, "%s", item );
      // use a variable to increment or decrement the value based on the input.
      switch(ch)
      {
          case KEY_UP:
                i--;
                i = ( i<0 ) ? 4 : i;
                break;
          case KEY_DOWN:
                i++;
                i = ( i>4 ) ? 0 : i;
                break;
          case 10:
                loadSelection(i);
                break;
          case KEY_RIGHT:
                loadSelection(i);
                break;
       }
      // now highlight the next item in the list.
      wattron(terminal_shop, A_STANDOUT );

      sprintf(item, "%-7s",  list[i]);
      mvwprintw(terminal_shop, i+1, 2, "%s", item);
      wattroff(terminal_shop, A_STANDOUT );
   }

  //getch();  //wait for user input

  delwin(terminal_shop);

  endwin(); //end curses mode
} while (open == TRUE);

  return 0;
}

void loadSelection(int s)
{
  printw("Load selection function found");
  //if (s==5)
  //{
    //exit(0);
  //}
  //std::terminate();
  open = FALSE;
}
