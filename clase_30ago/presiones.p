unset log
unset label
set xtic auto
set ytic auto
set title "Presiones"
set xlabel "Nw/m"
set ylabel "k"
#set xrange [10:45]
#set yrange [1:70]
set grid
set autoscale
plot 'D.dat' using 1 w l title 'presionA', 'E.dat' using 1 w l title 'presionB' 

