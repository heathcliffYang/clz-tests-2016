#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "clz.h"

// Harley's algorithm version
int main(void)
{

    uint32_t X = 1;
       
    for( ;X<4294967295;X*2)
    {
    harley(X);
    }
    return 0;
}
