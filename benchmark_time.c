#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "clz.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0

int main(void)
{
    struct timespec start = {0, 0};
    struct timespec end = {0, 0};

    uint32_t X = 0;
    unsigned int time[loop];

    for(; X < 4294967295; X++) {

    printf("%d,", X);

    // iteration version
        clock_gettime(CLOCK_ID, &start);
        iteration(X);
        clock_gettime(CLOCK_ID, &end);
        time=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
    printf("%lf,", time);


    // binarySearch version
    for(i = 0; i < loop; i++) {
        clock_gettime(CLOCK_ID, &start);
        binarySearch(X);
        clock_gettime(CLOCK_ID, &end);
        time[i]=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
        sum+=time[i];
    }
    avg=sum/loop;
    printf("%lf,", avg);


    // byteShift version
    
    for(i = 0; i < loop; i++) {
        clock_gettime(CLOCK_ID, &start);
        byteShift(X);
        clock_gettime(CLOCK_ID, &end);
        time[i]=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
        sum+=time[i];
    }
    avg=sum/loop;
    printf("%lf,", avg);

    // recursive version
    for(i = 0; i < loop; i++) {
        clock_gettime(CLOCK_ID, &start);
        recursive(X);
        clock_gettime(CLOCK_ID, &end);
        time[i]=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
        sum+=time[i];
    }
    avg=sum/loop;
    printf("%lf,", avg);

    // Harley's algorithm version
    for(i = 0; i < loop; i++) {
        clock_gettime(CLOCK_ID, &start);
        harley(X);
        clock_gettime(CLOCK_ID, &end);
        time[i]=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
        sum+=time[i];
    }
    avg=sum/loop;
    printf("%lf\n", avg);

    }

    return 0;
}

