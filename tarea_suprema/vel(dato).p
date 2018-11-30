set yrange[0:0.35]
set xrange[0:100]
set xlabel "dato digital {/Symbol d}"
set ylabel "rad/s"
f(x) = -3.1857e-02+3.5349e-03*x-6.5941e-05*x**2+2.8093e-16*x**3-7.3720e-181*x**4+5.4485e-10*x**5-1.2667e-11*x**6+1.0975e-13*x**7-3.3957e-16*x**8
plot 'tabla.txt' u 1:5 w lp title 'vel vs {/Symbol d}',f(x) title 'polinomio grado 8'
