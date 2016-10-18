CC = gcc
CFLAGS = -O0 -std=gnu99 -Wall
EXECUTABLE = \
	benchmark_clock_gettime

default: clz.o
	$(CC) $(CFLAGS) clz.o benchmark_time.c -o benchmark_time

.PHONY: clean default

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

gencsv: default
	for i in `seq 0 1 100`; do\
		printf "%d," $$i;\
		./benchmark_clock_gettime $$i;\
	done > result_runtime.csv

plot: result_time_compare.csv
	gnuplot runtime.gp

clean:
	rm -f $(EXECUTABLE) *.o *.s result_runtime.csv
