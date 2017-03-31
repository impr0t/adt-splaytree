#include <iostream>

#include "splaytree.h"

int main(int argc, const char *argv[])
{
    SplayTree s;
    s.root = s.insert(nullptr, 1);
    s.root = s.insert(s.root, 3);
    s.root = s.insert(s.root, 5);
    s.root = s.insert(s.root, 2);
    s.view(s.root);
}