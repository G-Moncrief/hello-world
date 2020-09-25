#include "graph.h"

class maze:public graph
{
  public:
	maze();
	void dfs(vector<int> &pred);
	void print_dfs_exitpath();
	void bfs(vector<int> &pred);
  	void print_bfs_exitpath();
	void printPath(int u, vector<int> pred);
  private:
	int start;
	int exit;
};



