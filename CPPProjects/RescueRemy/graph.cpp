#include "graph.h"
#include <cassert>

graph::graph()
{
  int vertex;
  cin >> size;
  adjList.resize(size,NULL);
  for(int i = 0; i < size; ++i) {
    cin >> vertex;
    while(vertex != -1) {
      adjList[i] = new vnode(vertex,adjList[i]); // insert at begining
      cin >> vertex;
    }
  }
}

