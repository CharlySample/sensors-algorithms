unset log
unset label
set xtic auto
set ytic auto
set title "Potencias"
set xlabel "W"
set ylabel "k"
#set xrange [10:45]
#set yrange [1:70]
set grid
set autoscale
plot 'D.dat' using 2 w l title 'potenciaA', 'E.dat' using 2 w l title 'potenciaB' 

