set terminal png
set output 'plots/untergrund_we.png'

#Zeit für Einzelmessung
t = 3000


set ylabel "Aktivität [Bq]"
set logscale y
set xlabel "Spannung U [V]"
plot 'untergrund_we.txt' u 1:2:(sqrt($2**2/t)) w yerrorbars title "Untergrund"
