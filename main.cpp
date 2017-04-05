#include <iostream>
#include <time.h>
#include "splaytree.h"

int main(int argc, const char *argv[])
{
    SplayTree s;
    long values = 10;
    for (int r = 1; r <= 1; r++)
    {
        s.root = nullptr;

        // insert values from 10 to 0, even only.
        for (long i = values; i >= 0; i--)
        {
            if (i % 2 == 0)
                s.root = s.insert(s.root, i);
        }

        // insert values from 10 to 0, odd only.
        for (long k = values; k >= 0; k--)
        {
            if (k % 2 != 0)
                s.root = s.insert(s.root, k);
        }

        /// START TIMED BLOCK 
        clock_t start = clock();
        for (long j = 0; j < values; j++)
        {
            s.remove(j);

            // uncomment to see all different traversals of the tree 
            //s.traverse(s.root);

            // uncomment to see the tree printed.
            //s.display(s.root);
        }

        // -- STATISTICS
        clock_t end = clock();
        unsigned int ticks = (unsigned int)(end - start);
        std::cout << "run " << r << " runtime: " << (((float)ticks) / CLOCKS_PER_SEC) << std::endl;
        values *= 2; // double our values.

        /// END TIMED BLOCK
    }

    s.root = nullptr;
    return 0;
}