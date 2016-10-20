#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "clz.h"

// binarySearch version
int main(void)
{

    uint32_t X = 1;
       
    for( ;X<4294967295;X*2)
    {
    binarySearch(X);
    }
    return 0;
}
