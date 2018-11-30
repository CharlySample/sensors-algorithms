set yrange[0:0.15]
set xrange[0:100]
set xlabel "dato digital {/Symbol d}"
set ylabel "rad/s"
f(x) = -0.0250544*x**0+0.00400006*x**1+3.12396e-14*x**2-8.60138e-178*x**3-3.56115e-08*x**4+5.65248e-10*x**5-1.07073e-174*x**6-4.47934e-14*x**7+2.10903e-16*x**8
plot 'tabla.txt' u 1:5 w lp title 'vel vs {/Symbol d}',f(x) title 'polinomio grado 8'
