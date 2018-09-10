set multiplot layout 2, 2
set yrange[0:40]
set xrange[0:10]
set xlabel "t(s)"
set ylabel "rad"
f6(x) = -0.258550*x**0+20.734243*x**1-38.680677*x**2+27.072841*x**3-7.725501*x**4+0.975784*x**5-0.045473*x**6 
f4(x) = 1.978753*x**0-11.475828*x**1+12.163039*x**2-2.512468*x**3+0.155875*x**4
f3(x) = -0.271123*x**0+0.191685*x**1+3.150704*x**2-0.356834*x**3
f8(x) = 0.003721*x**0-1.022802*x**1+29.145686*x**2-47.921037*x**3+31.873946*x**4-10.096545*x**5+1.616383*x**6-0.124401*x**7+0.003562*x**8
set title 'Ajuste cúbico'
plot 'tabla.txt' using 1:6 with lp title 's(x)' linetype 8, f3(x) title 's(t)' linetype 6
set title 'Ajuste cuarto'
plot 'tabla.txt' using 1:6 with lp title 's(x)' linetype 8, f4(x) title 's(t)' linetype 7
set title 'Ajuste sexto'
plot 'tabla.txt' using 1:6 with lp title 's(x)' linetype 8, f6(x) title 's(t)' linetype 10
set title 'Ajuste octavo'
plot 'tabla.txt' using 1:6 with lp title 's(x)' linetype 8, f8(x) title 's(t)' linetype 15
unset multiplot
