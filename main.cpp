#include <iostream>
#include <time.h>
#include <fstream>
#include "splaytree.h"

int main(int argc, const char *argv[])
{
    std::ofstream output;
    output.open("results.txt");

    SplayTree s;
    long values = 100000;
    for (int r = 1; r <= 1; r++)
    {
        s.root = nullptr;

        // insert values from values to 0, even only.
        for (long i = values; i >= 0; i--)
        {
            if (i % 2 == 0)
                s.root = s.insert(s.root, i);
        }

        // insert values from values to 0, odd only.
        for (long k = values; k >= 0; k--)
        {
            /// START TIMED BLOCK.
            clock_t start = clock();

            if (k % 2 != 0)
                s.root = s.insert(s.root, k);

            // -- STATISTICS
            clock_t end = clock();
            unsigned int ticks = (unsigned int)(end - start);
            //std::cout << "run " << r << " runtime: " << (((float)ticks) / CLOCKS_PER_SEC) << std::endl;
            output << (((float)ticks) / CLOCKS_PER_SEC) << std::endl;
            std::cout << (((float)ticks) / CLOCKS_PER_SEC) << std::endl;
            //values *= 2; // double our values.
            //s.traverse(s.root);
            /// END TIMED BLOCK
        }
    }

    s.root = nullptr;
    output.close();
    return 0;
}