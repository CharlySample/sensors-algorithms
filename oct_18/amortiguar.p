set grid
set yrange[-0.2:0.5]
set xrange[0:50]
set xlabel "t(s)"
set ylabel "distancia (m)"
set title 'Casos de un sistema masa resorte amortiguador'
plot 'sobre.txt' using 2:1 with lp title 'Sobreamortiguado' linetype 7, 'criticamente.txt' u 2:1 w lp title'Criticamente amortiguado' linetype 8, 'subamortiguado.txt' u 2:1 w lp title 'Subamortiguado' linetype 9

