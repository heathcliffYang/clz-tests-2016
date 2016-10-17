#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "clz.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW

int main(int argc, char const *argv[])
{
    struct timespec start = {0, 0};
    struct timespec end = {0, 0};

    if (argc < 2) return -1;

    int input = atoi(argv[1]);
    int output = 0;

    // iteration
    clock_gettime(CLOCK_ID, &start);
    output = iteration(input);
    clock_gettime(CLOCK_ID, &end);
    printf("%d,", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/ONE_SEC);

    // binarySearch
    clock_gettime(CLOCK_ID, &start);
    output = binarySearch(input);
    clock_gettime(CLOCK_ID, &end);
    printf("%d,", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/ONE_SEC);

    // byteShift
    clock_gettime(CLOCK_ID, &start);
    output = byteShift(input);
    clock_gettime(CLOCK_ID, &end);
    printf("%d,", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/ONE_SEC);

    // recursive
    clock_gettime(CLOCK_ID, &start);
    output = recursive(input);
    clock_gettime(CLOCK_ID, &end);
    printf("%d,", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/ONE_SEC);

    // harley    
    clock_gettime(CLOCK_ID, &start);
    output = harley(input);
    clock_gettime(CLOCK_ID, &end);
    printf("%d\n", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/ONE_SEC);

}
