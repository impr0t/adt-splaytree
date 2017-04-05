#ifndef node
#define node

class Node
{
public:
  Node(long data)
  {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
  ~Node()
  {
    if (left)
      delete left;
    if (right)
      delete right;
  }
  long getData()
  {
    return this->data;
  }
  Node *left;
  Node *right;

private:
  long data;
};

#endif