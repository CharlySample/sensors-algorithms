unset log
unset label
set xtic auto
set ytic auto
set title "Tarea delfinA"
set xlabel "m/s"
set ylabel "tiempo"
#set xrange [10:45]
#set yrange [1:70]
set grid
set autoscale
plot 'delfina.txt' using 1 w l title 'xp', 'delfina.txt' using 2 w l title 'yp' 


