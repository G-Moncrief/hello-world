#include <iostream>
#include "maze.h"

using namespace std;

int main()
{
  maze RatHaus;
  RatHaus.print_dfs_exitpath();
  cout << endl;
  RatHaus.print_bfs_exitpath();
  cout << endl;
  return 0;
}

