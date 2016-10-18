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

    if (argc < 2) return -1;

    int X = atoi(argv[1]);
    int i, loop = 1,sum;
    double avg;
    double time[loop];

    // iteration version
    for(i = 0; i < loop; i++) {
        clock_gettime(CLOCK_ID, &start);
        iteration(X);
        clock_gettime(CLOCK_ID, &end);
        time[i]=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
        sum+=time[i];
    }
    avg=sum/loop;
    printf("%lf,", (double) avg);
//    printf("%lf,", (double) time);


    // binarySearch version
    for(i = 0; i < loop; i++) {
        clock_gettime(CLOCK_ID, &start);
        binarySearch(X);
        clock_gettime(CLOCK_ID, &end);
        time[i]=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
        sum+=time[i];
    }
    avg=sum/loop;
    printf("%lf,", (double) avg);
//    printf("%lf,", (double) time);


    // byteShift version
    
    for(i = 0; i < loop; i++) {
        clock_gettime(CLOCK_ID, &start);
        byteShift(X);
        clock_gettime(CLOCK_ID, &end);
        time[i]=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
        sum+=time[i];
    }
    avg=sum/loop;
    printf("%lf,", (double) avg);
//    printf("%lf,", (double) time);

    // recursive version
    for(i = 0; i < loop; i++) {
        clock_gettime(CLOCK_ID, &start);
        recursive(X);
        clock_gettime(CLOCK_ID, &end);
        time[i]=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
        sum+=time[i];
    }
    avg=sum/loop;
    printf("%lf,", (double) avg);
//    printf("%lf,", (double) time);

    // Harley's algorithm version
    for(i = 0; i < loop; i++) {
        clock_gettime(CLOCK_ID, &start);
        harley(X);
        clock_gettime(CLOCK_ID, &end);
        time[i]=(end.tv_sec - start.tv_sec)*ONE_SEC +(end.tv_nsec - start.tv_nsec);
        sum+=time[i];
    }
    avg=sum/loop;
    printf("%lf\n", (double) avg);
//    printf("%lf,", (double) time);


    return 0;
}

