#include <iostream>

#include "splaytree.h"

int main(int argc, const char *argv[])
{
    SplayTree s;
    for (int i = 10; i >= 0; i--)
    {
        s.root = s.insert(s.root, i);
        s.view(s.root);
    }

    for (int i = 0; i <= 10; i++)
    {
        if (i % 2 == 0)
        {
            std::cout << "removing " << i << std::endl;
            s.remove(i);
            s.view(s.root);
        }
    }
}