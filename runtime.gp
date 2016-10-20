set xlabel 'Input value'
set ylabel 'Time(nanosec)'
set autoscale fix
set style fill solid
set datafile separator ","
set title 'clz-test runtime'
set term png enhanced font 'Verdana,10'
set output 'time_compare.png'

plot 'result_runtime.csv' using 1:2 title 'iteration' with linespoints, \
     'result_runtime.csv' using 1:3 title 'binary' with linespoints, \
     'result_runtime.csv' using 1:4 title 'byteShift' with linespoints, \
     'result_runtime.csv' using 1:5 title 'recursive' with linespoints, \
     'result_runtime.csv' using 1:6 title 'harley' with linespoints, \

