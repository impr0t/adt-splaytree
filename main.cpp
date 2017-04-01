#include <iostream>
#include "splaytree.h"

#define TESTS 20

int main(int argc, const char *argv[])
{
    SplayTree s;
    for (int i = TESTS; i >= 0; i--)
    {
        std::cout << "inserting " << i << std::endl;
        s.root = s.insert(s.root, i);
        s.traverse(s.root);
        s.display(s.root);
    }
    for (int y = 0; y <= TESTS; y++)
    {
        if (y % 2 == 0)
        {
            std::cout << "removing " << y << std::endl;
            s.remove(y);
            s.traverse(s.root);
            s.display(s.root);
        }
    }

    // reinsert an even element, should restructure tree.
    //std::cout << "reinsert an even element" << std::endl;
    s.root = s.insert(s.root, 2);
    s.traverse(s.root);
    s.display(s.root);

    // try to insert a duplicate element, should be thrown out.
    //std::cout << "insert duplicate" << std::endl;
    s.root = s.insert(s.root, 2);
    s.traverse(s.root);
    s.display(s.root);
}