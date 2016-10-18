CC = gcc
CFLAGS = -O0 -std=gnu99 -Wall
EXECUTABLE = \
	benchmark_time

default: clz.o
	$(CC) $(CFLAGS) clz.o benchmark_time.c -o benchmark_time

.PHONY: clean default

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

gencsv: default
	for i in `seq 0 1 4294967295`; do\
		printf "%d," $$i;\
		./benchmark_time $$i;\
	done > result_runtime.csv

plot: result_runtime.csv
	gnuplot runtime.gp

clean:
	rm -f $(EXECUTABLE) *.o *.s result_runtime.csv
