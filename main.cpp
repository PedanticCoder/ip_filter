#include "filter.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    try
    {
	std::vector<strVector> ip_pool;
        readAllPool(ip_pool);
        reverseIpSort(ip_pool);
        filter(1, ip_pool);
        filter(46, 70, ip_pool);
        filterAny(46, ip_pool);
   }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}



