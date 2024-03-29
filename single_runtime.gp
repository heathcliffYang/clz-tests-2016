set xlabel 'Input value'
set ylabel 'Time(nanosec)'
set autoscale fix
set style fill solid
set datafile separator ","
set title 'clz-test runtime'
set term png enhanced font 'Verdana,10'
set output 'time_compare_iter.png'

plot 'result_runtime_iter_0.csv' using 1:2 title 'iteration' with linespoints, \
