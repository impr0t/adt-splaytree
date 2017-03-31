#ifndef node
#define node

class Node
{
public:
  Node(int data)
  {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
  ~Node()
  {
    delete left;
    delete right;
  }
  int getData()
  {
    return this->data;
  }
  Node *left;
  Node *right;

private:
  int data;
};

#endif