set terminal png enhanced size 1200,800
set output 'Bilder/lockin.png'

set grid

f(x) = a* x + b

fit f(x) 'lockin.csv' using 1:2:(0.002) via a,b

set xlabel 'U in V'
set ylabel 'v in MHz'

plot 'lockin.csv' using 1:2:(0.01):(0.002) with xyerrorbars t 'Resonanzen' , f(x) t 'ax + b'
