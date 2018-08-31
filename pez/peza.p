unset log
unset label
set xtic auto
set ytic auto
set title "Ejercicio A"
set xlabel "x"
set ylabel "y"
#set xrange [10:45]
#set yrange [1:70]
set grid
set autoscale
plot 'peza.txt' using 1 w l title 'xp', 'peza.txt' using 2 w l title 'yp' 

