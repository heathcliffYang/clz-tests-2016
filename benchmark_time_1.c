#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "clz.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0

// iteration version
int main(int argc, char const *argv[])
{
    struct timespec start = {0, 0};
    struct timespec end = {0, 0};
    uint32_t X = 0;
    uint32_t loop = atoi(argv[1]);
    unsigned int time;
       
    for( ;X < loop; X++)
    {
    printf("%u,", X);
    clock_gettime(CLOCK_ID, &start);
    iteration(X);
    clock_gettime(CLOCK_ID, &end);
    time=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
    printf("%u\n",  time);
    }
    return 0;
}
