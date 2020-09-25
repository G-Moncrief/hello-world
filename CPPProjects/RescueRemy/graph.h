
#ifndef GRPH
#define GRPH

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct vnode {
  int v; // vertex
  vnode *next;
  vnode(int u, vnode *n) {v=u; next=n;}
};

typedef vnode * vnodeptr;


class graph {
 public:
    graph(); // interactive constructor using cin

 protected:
    int size;
    vector<vnodeptr> adjList;
};

#endif
