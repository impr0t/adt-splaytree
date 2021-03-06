#include "splaytree.h"
#include <iostream>
#include <iomanip>

/**
* This function inserts a new node into the tree.
*/
Node *SplayTree::insert(Node *n, long data)
{
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

void SplayTree::remove(long data)
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
Node *SplayTree::find(Node *n, long data)
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
Node *SplayTree::splay(Node *n, long data)
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

        // check the immediate left child
        // for having data > our input data
        if (n->left->getData() > data)
        {
            // continuously splay lesser data upwards if we
            // keep running into greater data.
            n->left->left = splay(n->left->left, data);
            n = rotateRight(n); // right rotation does this.
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
            // zig zag
            n->right->left = splay(n->right->left, data);
            if (n->right->left != nullptr)
                n->right = rotateRight(n->right);
        }
        else if (n->right->getData() < data)
        {
            // keep splaying downward
            n->right->right = splay(n->right->right, data);
            n = rotateLeft(n);
        }

        if (n->right == nullptr)
            return n;
        else
            return rotateLeft(n);
    }
}

/*
* Generalized view function.
*/
void SplayTree::traverse(Node *n)
{
    if (n == nullptr)
        return;

    long r = 0;

    std::cout << "pre-order: ";
    r = traverse(n, ePreorder);
    std::cout << std::endl;

    std::cout << "in-order: ";
    traverse(n, eInorder);
    std::cout << std::endl;

    std::cout << "post-order: ";
    traverse(n, ePostorder);
    std::cout << std::endl;

    std::cout << "size (bytes): " << r << std::endl;
}

/**
* Displays the tree in a many different manners of way.
*/
long SplayTree::traverse(Node *n, Order o)
{
    long size = sizeof(n);

    if (n == nullptr)
        return size;

    switch (o)
    {
    case ePreorder:
        std::cout << n->getData() << " ";
        size += traverse(n->left, o);
        size += traverse(n->right, o);
        break;
    case eInorder:
        size += traverse(n->left, o);
        std::cout << n->getData() << " ";
        size += traverse(n->right, o);
        break;
    case ePostorder:
        size += traverse(n->left, o);
        size += traverse(n->right, o);
        std::cout << n->getData() << " ";
        break;
    }
    return size;
}

void SplayTree::display(Node *n)
{
    if (n != nullptr)
    {
        std::cout << "horrible visual representation:" << std::endl;
        display(n, 0);
        std::cout << std::flush;
    }
}

void SplayTree::display(Node *n, long indent)
{
    if (n != nullptr)
    {
        display(n->right, indent + 4);
        if (indent > 0)
            std::cout << std::setw(indent) << " ";
        std::cout << n->getData() << std::endl;
        display(n->left, indent + 4);
    }
}