set yrange[0:0.03]
set xrange[0:1300]
set xlabel "t(s)"
set ylabel "m/s"
f(x) =   -3.0499e-02+2.5907e-04*x-4.5207e-07*x**2+3.5114e-10*x**3-1.0179e-13*x**4+1.8693e-181*x**5
plot 'tabla.txt' u 3:5 w lp title 'vel vs t(s)',f(x) title 'polinomio grado 5'

