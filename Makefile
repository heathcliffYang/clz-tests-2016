CC = gcc
CFLAGS = -O0 -std=gnu99 -Wall
EXECUTABLE = \
	benchmark_time_1 benchmark_time_2 benchmark_time_3 benchmark_time_4 benchmark_time_5

default: clz.o
	$(CC) $(CFLAGS) clz.o benchmark_time.c -o benchmark_time
	$(CC) $(CFLAGS) clz.o benchmark_time_1.c -o benchmark_time_1
	$(CC) $(CFLAGS) clz.o benchmark_time_2.c -o benchmark_time_2
	$(CC) $(CFLAGS) clz.o benchmark_time_3.c -o benchmark_time_3
	$(CC) $(CFLAGS) clz.o benchmark_time_4.c -o benchmark_time_4
	$(CC) $(CFLAGS) clz.o benchmark_time_5.c -o benchmark_time_5

.PHONY: clean default

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

gencsv: default
	for i in `seq 0 67108864 4227858432`; do\
		./benchmark_time_1 $$i > result_runtime_iter_"$$i".csv;\
	done

plot: result_runtime.csv
	gnuplot runtime.gp

perf_iter:default
	perf stat -e cache-misses,cpu-cycles,instructions,branch-misses ./benchmak_time_1

perf_bin:default
	perf stat -e cache-misses,cpu-cycles,instructions,branch-misses ./benchmak_time_2

perf_byte:default
	perf stat -e cache-misses,cpu-cycles,instructions,branch-misses ./benchmak_time_3

perf_recur:default
	perf stat -e cache-misses,cpu-cycles,instructions,branch-misses ./benchmak_time_4

perf_harley:default
	perf stat -e cache-misses,cpu-cycles,instructions,branch-misses ./benchmak_time_5



clean:
	rm -f $(EXECUTABLE) *.o *.s *.csv
