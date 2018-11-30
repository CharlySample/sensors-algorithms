set yrange[0:100]
set xrange[0:0.35]
set ylabel "dato digital {/Symbol d}"
set xlabel "rad/s"
f(x) = 10.219556*x**0+2157.628113*x**1-262954.615377*x**2+10421912.785740*x**3
plot 'tabla.txt' u 5:1 w lp title '{/Symbol d} vs vel',f(x) title 'polinomio grado 3'
