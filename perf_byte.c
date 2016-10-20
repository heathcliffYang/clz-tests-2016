#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "clz.h"

// byte shift 
int main(void)
{

    uint32_t X = 1;
       
    for( ;X<4294967295;X*2)
    {
    byteShift(X);
    }
    return 0;
}
