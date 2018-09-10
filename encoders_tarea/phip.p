set multiplot layout 2, 2
set yrange[-3:10]
set xrange[0:10]
set xlabel "t(s)"
set ylabel "rad/s"
f6(x) = -0.070228*x**0+19.475728*x**1-40.684667*x**2+30.502509*x**3-9.798829*x**4+1.396970*x**5-0.072552*x**6
f4(x) = 1.254385*x**0-6.178506*x**1+7.048941*x**2-1.882899*x**3+0.141366*x**4
f3(x) = -0.786057*x**0+4.402920*x**1-1.124468*x**2+0.072075*x**3
f8(x) = 0.007138*x**0+7.785173*x**1+0.472512*x**2-21.359369*x**3+22.101521*x**4-9.277968*x**5+1.909510*x**6-0.191503*x**7+0.007488*x**8
set title 'Ajuste cúbico'
plot 'tabla.txt' using 1:4 with lp title 'phip' linetype 8, f3(x) title 'phi(t)' linetype 6
set title 'Ajuste cuarto'
plot 'tabla.txt' using 1:4 with lp title 'phip' linetype 8, f4(x) title 'phi(t)' linetype 7
set title 'Ajuste sexto'
plot 'tabla.txt' using 1:4 with lp title 'phip' linetype 8, f6(x) title 'phi(t)' linetype 10
set title 'Ajuste octavo'
plot 'tabla.txt' using 1:4 with lp title 'phip' linetype 8, f8(x) title 'phi(t)' linetype 15
unset multiplot
