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
	./benchmark_time > result_runtime.csv

plot: result_runtime.csv
	gnuplot runtime.gp

clean:
	rm -f $(EXECUTABLE) *.o *.s result_runtime.csv
