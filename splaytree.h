#ifndef splaytree
#define splaytree

#include "node.h"

enum Order { ePreorder, eInorder, ePostorder};

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
  void traverse(Node *n);
  void traverse(Node *n, Order o);
  void display(Node *n);
  void display(Node *n, int indent);
  Node *root;
};

#endif