unset log
unset label
set xtic auto
set ytic auto
set title "Tarea delfinB"
set xlabel "tiempo"
set ylabel "radianes"
set xrange [0:91]
set yrange [-3:3]
set grid
#set autoscale
   plot 'delfinb.txt' using 1 w l title 'phip1', 'delfinb.txt' using 2 w l title 'phip2','delfinb.txt' using 3 w l title 'phip3' 


