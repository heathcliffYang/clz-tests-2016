#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "clz.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0
// iteration version

int main(void)
{
    struct timespec start = {0, 0};
    struct timespec end = {0, 0};
    int result;
    uint32_t X = 0;
    unsigned int time;
       
    for( X ;X<4294967295;X++)
    {
    clock_gettime(CLOCK_ID, &start);
    result=iteration(X);
    clock_gettime(CLOCK_ID, &end);
    time=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
    printf("%lf=%d,", (double) time,(int)result);
    }
    return 0;
}
