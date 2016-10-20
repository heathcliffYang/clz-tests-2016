#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "clz.h"

// iteration version
int main(void)
{

    uint32_t X = 1;
       
    for( ;X<4294967295;X*2)
    {
    iteration(X);
    }
    return 0;
}
