set xlabel 'Input value'
set ylabel 'Time(nanosec)'
set autoscale fix
set style fill solid
set datafile separator ","
set title 'clz-test runtime'
set term png enhanced font 'Verdana,10'
set output 'time_compare.png'

plot 'result_runtime.csv' using 1:2 title 'function1' with linespoints, \
     'result_runtime.csv' using 1:3 title 'function2' with linespoints, \
     'result_runtime.csv' using 1:4 title 'function3' with linespoints, \
     'result_runtime.csv' using 1:5 title 'function4' with linespoints, \
     'result_runtime.csv' using 1:6 title 'function5' with linespoints, \

