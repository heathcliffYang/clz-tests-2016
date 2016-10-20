set xlabel 'Input value'
set ylabel 'Time(nanosec)'
set autoscale fix
set style fill solid
set datafile separator ","
set title 'clz-test runtime'
set term png enhanced font 'Verdana,10'
set output 'time_compare.png'

plot 'result_runtime_iter_.csv' using 1:2 title 'iteration' with linespoints, \
     'result_runtime_bin_.csv' using 1:2 title 'binary' with linespoints, \
     'result_runtime_byte_.csv' using 1:2 title 'byteSearch' with linespoints, \
     'result_runtime_recur.csv' using 1:2 title 'recursive' with linespoints, \
     'result_runtime_harley.csv' using 1:2 title 'harley' with linespoints, \

