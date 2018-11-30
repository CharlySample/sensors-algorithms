set multiplot layout 2, 2 title "Tiempo vs pulsos"
set yrange[0:150]
set xrange[0:10]
set xlabel "t(s)"
set ylabel "{/Symbol h}"
f6(x) = -1.028738*x**0+82.499002*x**1-153.905654*x**2+107.719504*x**3-30.738818*x**4+3.882523*x**5-0.180930*x**6 
f4(x) = 7.873213*x**0-45.660907*x**1+48.395235*x**2-9.996800*x**3+0.620209*x**4
f3(x) = -1.078764*x**0+0.762693*x**1+12.536262*x**2-1.419798*x**3
f5(x) = 1.221000*x**0+30.600776*x**1-50.536211*x**2+33.910701*x**3-7.186300*x**4+0.473787*x**5
set title 'Ajuste cúbico'
plot 'tabla.txt' using 1:2 with lp title 'y(x)' linetype 8, f3(x) title 'y(t)' linetype 6
set title 'Ajuste cuarto'
plot 'tabla.txt' using 1:2 with lp title 'y(x)' linetype 8, f4(x) title 'y(t)' linetype 7
set title 'Ajuste sexto'
plot 'tabla.txt' using 1:2 with lp title 'y(x)' linetype 8, f6(x) title 'y(t)' linetype 10
set title 'Ajuste quinto'
plot 'tabla.txt' using 1:2 with lp title 'y(x)' linetype 8, f5(x) title 'y(t)' linetype 15
unset multiplot
