CC = gcc
CFLAGS = -O0 -std=gnu99 -Wall
EXECUTABLE = \
	benchmark_time_1 benchmark_time_2 benchmark_time_3 \
	benchmark_time_4 benchmark_time_5
RESULT = \
	result_runtime_1.csv result_runtime_2.csv result_runtime_3.csv \
	result_runtime_4.csv result_runtime_5.csv

default: clz.o
	$(CC) $(CFLAGS) clz.o benchmark_time_1.c -o benchmark_time_1
	$(CC) $(CFLAGS) clz.o benchmark_time_2.c -o benchmark_time_2
	$(CC) $(CFLAGS) clz.o benchmark_time_3.c -o benchmark_time_3
	$(CC) $(CFLAGS) clz.o benchmark_time_4.c -o benchmark_time_4
	$(CC) $(CFLAGS) clz.o benchmark_time_5.c -o benchmark_time_5

.PHONY: clean default

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

gencsv: default
	j = 0;
	for i in `seq 0 10 100`;do \
		j++;\
		./benchmark_time_1 $$i > result_time_iter_$$j.csv;\
	done
#for i in `seq 0 67108864 4294967296`;\
#	./benchmark_time_3 > result_runtime_3.csv
#	./benchmark_time_4 > result_runtime_4.csv
#	./benchmark_time_5 > result_runtime_5.csv

plot: $(RESULT)
	gnuplot runtime.gp

perf_iter:default
	perf stat -e cache-misses,cpu-cycles,instructions,branch-misses ./perf_iter

perf_bin:default
	perf stat -e cache-misses,cpu-cycles,instructions,branch-misses ./perf_bin

perf_byte:default
	perf stat -e cache-misses,cpu-cycles,instructions,branch-misses ./perf_byte

perf_recur:default
	perf stat -e cache-misses,cpu-cycles,instructions,branch-misses ./perf_recur

perf_harley:default
	perf stat -e cache-misses,cpu-cycles,instructions,branch-misses ./perf_harley

clean:
	rm -f $(EXECUTABLE) *.o *.s $(RESULT)
