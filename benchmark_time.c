#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "clz.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0

int main(int argc, char const *argv[])
{
    struct timespec start = {0, 0};
    struct timespec end = {0, 0};

    uint32_t X = atoi(argv[1]);
    unsigned int time;
    

    
    // iteration version
    clock_gettime(CLOCK_ID, &start);
    iteration(X);
    clock_gettime(CLOCK_ID, &end);
    time=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
    printf("%lf,", (double) time);


    // binarySearch version
    clock_gettime(CLOCK_ID, &start);
    binarySearch(X);
    clock_gettime(CLOCK_ID, &end);
    time=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
    printf("%lf,", (double) t./ime);


    // byteShift version
    
    clock_gettime(CLOCK_ID, &start);
    byteShift(X);
    clock_gettime(CLOCK_ID, &end);
    time=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
    printf("%lf,", (double) time);

    // recursive version

    clock_gettime(CLOCK_ID, &start);
    recursive(X);
    clock_gettime(CLOCK_ID, &end);
    time=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
    printf("%lf,", (double) time);

    // Harley's algorithm version
    clock_gettime(CLOCK_ID, &start);
    harley(X);
    clock_gettime(CLOCK_ID, &end);
    time=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
    printf("%lf,", (double) time);


    return 0;
}

