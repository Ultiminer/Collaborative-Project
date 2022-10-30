#include <iostream>
#include "primitives.h"
#include "statistics.h"
#define ENTRY_STATEMENT "Basic test tools Ver.1.0.0"

int main(void)
{
    std::cout<<ENTRY_STATEMENT<<std::endl;
    std::vector<int> vec={1,2,3};
    
    std::cout<<max(vec);

    return 0;
}