unset log
unset label
set xtic auto
set ytic auto
set title "Tarea delfinB"
set xlabel "x"
set ylabel "y"
#set xrange [10:45]
#set yrange [1:70]
set grid
set autoscale
plot 'delfinc.txt' using 1 w l title 'phip1', 'delfinc.txt' using 2 w l title 'phip2','delfinc.txt' using 3 w l title 'phip3'


