#ifndef splaytree
#define splaytree

#include "node.h"

class SplayTree
{
public:
  SplayTree() {}
  ~SplayTree() { delete root; }
  Node *insert(Node *n, int data);
  void remove(int data);
  Node *find(Node *n, int data);
  Node *splay(Node *n, int data);
  Node *rotateRight(Node *a);
  Node *rotateLeft(Node *a);
  void view(Node *n);
  Node *root;
};

#endif