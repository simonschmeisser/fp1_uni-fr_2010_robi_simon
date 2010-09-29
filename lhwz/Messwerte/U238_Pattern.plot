set terminal png
set output 'plots/U238.png'

set ylabel "Aktivität Bq"
set logscale y
set xlabel "Spannung U [V]"
plot 'U238_Pattern.txt' u 1:2:(sqrt($2)) w yerrorbars title "238-Uran"
