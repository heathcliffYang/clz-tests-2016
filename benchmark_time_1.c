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
    uint32_t X = 0;
    unsigned int time;
       
    for( ;X<4294967295;X++)
    {
    clock_gettime(CLOCK_ID, &start);
    iteration(X);
    clock_gettime(CLOCK_ID, &end);
    time=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
    printf("%u,",  time);
    }
    return 0;
}
