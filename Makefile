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

perf_iter:default
	perf stat -e cache-misses,cpu-cycles,instructions,branch-misses ./benchmak_time_1.c

perf_bin:default
	perf stat -e cache-misses,cpu-cycles,instructions,branch-misses ./benchmak_time_2.c

perf_byte:default
	perf stat -e cache-misses,cpu-cycles,instructions,branch-misses ./benchmak_time_3.c

perf_recur:default
	perf stat -e cache-misses,cpu-cycles,instructions,branch-misses ./benchmak_time_4.c

perf_harley:default
	perf stat -e cache-misses,cpu-cycles,instructions,branch-misses ./benchmak_time_5.c



clean:
	rm -f $(EXECUTABLE) *.o *.s result_runtime.csv
