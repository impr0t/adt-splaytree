#ifndef splaytree
#define splaytree

#include "node.h"

enum Order
{
  ePreorder,
  eInorder,
  ePostorder
};

class SplayTree
{
public:
  SplayTree() {}
  ~SplayTree()
  {
    if (root)
      delete root;
  }
  Node *insert(Node *n, long data);
  void remove(long data);
  Node *find(Node *n, long data);
  Node *splay(Node *n, long data);
  Node *rotateRight(Node *a);
  Node *rotateLeft(Node *a);
  void traverse(Node *n);
  void traverse(Node *n, Order o);
  void display(Node *n);
  void display(Node *n, long indent);
  Node *root;
};

#endif