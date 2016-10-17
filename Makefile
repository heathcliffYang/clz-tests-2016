CC = gcc
CFLAGS = -O0 -std=gnu99 -Wall
EXECUTABLE = \
	benchmark_clock_gettime

default: clz.o
	$(CC) $(CFLAGS) clz.c -o clz.o
	$(CC) $(CFLAGS) clz.o benchmark_clock_gettime.c -o benchmark_clock_gettime -lm

gencsv: default
	for i in `seq 0 1 4294967295`; do\
		printf "%d," $$i;\
		./benchmark_clock_gettime $$i;\
	done > result_runtime.csv

plot: result_time_compare.csv
	gnuplot runtime.gp
