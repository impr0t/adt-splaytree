#include "splaytree.h"
#include <iostream>

void debug(std::string message)
{
    std::cout << message << std::endl;
}

/**
* This function inserts a new node into the tree.
*/
Node *SplayTree::insert(Node *n, int data)
{
    std::cout << "inserting " << data << std::endl;

    if (n == nullptr)
    {
        return new Node(data);
    }

    n = splay(n, data);

    if (n->getData() == data)
        return n;

    Node *newest = new Node(data);

    if (n->getData() > data)
    {
        newest->right = n;
        newest->left = n->left;
        n->left = nullptr;
    }
    else
    {
        newest->left = n;
        newest->right = n->right;
        n->right = nullptr;
    }

    return newest;
}

void SplayTree::remove(int data)
{
    if (root == nullptr)
        return;

    root = splay(root, data);

    if (root->getData() == data)
    {
        if (root->left == nullptr)
        {
            root = root->right;
        }
        else
        {
            Node *r = root->right;
            root = root->left;
            splay(root, data);
            root->right = r;
        }
    }
}

/**
* This function effectively splays a node
* To the root of the tree.
*/
Node *SplayTree::find(Node *n, int data)
{
    return splay(n, data);
}

/**
* This function rotates a node right.
* The node to rotate on is provided as an argument.
*/
Node *SplayTree::rotateRight(Node *a)
{
    Node *b = a->left;
    a->left = b->right;
    b->right = a;
    return b;
}

/**
* This function rotates a node left.
* The node to rotate on is provided as an argument.
*/
Node *SplayTree::rotateLeft(Node *a)
{
    Node *b = a->right;
    a->right = b->left;
    b->left = a;
    return b;
}

/**
* This is the primary workhorse of the splay tree.
* We have a few conditions to look at.
* Since the Splay Tree is based on a BST
* We know our data is stored in a sorted manner
* We can then traverse this data like wise and
* Splay elements recursively to the top when we look for them.
* This element also auto balances our tree.
*/
Node *SplayTree::splay(Node *n, int data)
{
    // if our node is null or the data is what we're looking for
    // just return this.
    if (n == nullptr || n->getData() == data)
        return n;

    // since the splay tree is a binary search tree with some fanciness
    // we can locate out data using the bst search method.
    if (n->getData() > data)
    {
        // can't find it.'
        if (n->left == nullptr)
            return n;

        if (n->left->getData() > data)
        {
            // zig-zig
            n->left->left = splay(n->left->left, data);
            n = rotateRight(n);
        }
        else if (n->left->getData() < data)
        {
            n->left->right = splay(n->left->right, data);

            if (n->left->right != nullptr)
                n->left = rotateLeft(n->left);
        }

        if (n->left == nullptr)
            return n;
        else
            return rotateRight(n);
    }
    else
    {
        // if our right node is not there, we can just return this node
        // we weren't able to find it.
        if (n->right == nullptr)
            return n;

        // so if we're still traversing we can find the data
        // here we have a conditon where we'll need to zig-zag.'
        if (n->right->getData() > data)
        {
            // zig-zag
            n->right->left = splay(n->right->left, data);
            if (n->right->left != nullptr)
                n->right = rotateRight(n->right);
        }
        else if (n->right->getData() < data)
        {
            n->right->right = splay(n->right->right, data);
            n = rotateLeft(n);
        }

        if (n->right == nullptr)
            return n;
        else
            return rotateLeft(n);
    }
}

/**
* Function displays an in-order traversal of
* the data structure. Since this is a BST we're'
* expecting a sorted list.
*/
void SplayTree::view(Node *n)
{
    if (n == nullptr)
        return;

    view(n->left);
    std::cout << n->getData() << " ";
    view(n->right);
}