#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "clz.h"
#include <math.h>

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0

int main(int argc, char const *argv[])
{
    struct timespec start = {0, 0};
    struct timespec end = {0, 0};

    if (argc < 2) return -1;

    int X = atoi(argv[1]);
    int i, loop = 10,sum;
    double avg;
    double time[loop];
    // recursive version
    for(i = 0; i < loop; i++) {
        clock_gettime(CLOCK_ID, &start);
        clz_recur(X);
        clock_gettime(CLOCK_ID, &end);
        time[i]=(end.tv_sec - start.tv_sec) +(end.tv_nsec - start.tv_nsec)/ONE_SEC;
        sum+=time[i];
    }
    avg=sum/loop;
    printf("%lf,", (double) avg);
    printf("%lf,", (double) time);


    // iteration version
    for(i = 0; i < loop; i++) {
        clock_gettime(CLOCK_ID, &start);
        clz_iter(X);
        clock_gettime(CLOCK_ID, &end);
        time[i]=(end.tv_sec - start.tv_sec) +(end.tv_nsec - start.tv_nsec)/ONE_SEC;
        sum+=time[i];
    }
    avg=sum/loop;
    printf("%lf,", (double) avg);
    printf("%lf,", (double) time);


    // binary search technique
    
    for(i = 0; i < loop; i++) {
        clock_gettime(CLOCK_ID, &start);
        clz_bi_search(X);
        clock_gettime(CLOCK_ID, &end);
        time[i]=(end.tv_sec - start.tv_sec) +(end.tv_nsec - start.tv_nsec)/ONE_SEC;
        sum+=time[i];
    }
    avg=sum/loop;
    printf("%lf,", (double) avg);
    printf("%lf,", (double) time);

    // byte-shift version
    for(i = 0; i < loop; i++) {
        clock_gettime(CLOCK_ID, &start);
        clz_byte_shift(X);
        clock_gettime(CLOCK_ID, &end);
        time[i]=(end.tv_sec - start.tv_sec) +(end.tv_nsec - start.tv_nsec)/ONE_SEC;
        sum+=time[i];
    }
    avg=sum/loop;
    printf("%lf,", (double) avg);
    printf("%lf,", (double) time);

    // Harley's algorithm
    
    for(i = 0; i < loop; i++) {
        clock_gettime(CLOCK_ID, &start);
        clz_harley_alg(X);
        clock_gettime(CLOCK_ID, &end);
        time[i]=(end.tv_sec - start.tv_sec) +(end.tv_nsec - start.tv_nsec)/ONE_SEC;
        sum+=time[i];
    }
    avg=sum/loop;
    printf("%lf,", (double) avg);
    printf("%lf,", (double) time);


    return 0;
}

