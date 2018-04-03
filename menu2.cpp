#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printmenu();

int main(int argc, char *argv[])
{
  std::vector<string> List;

  printmenu();
}

void printmenu()
{
  cout << "1. First";
  cout << "2. Second";
  cout << "3. Third";
  cout << "4. Close";
}
