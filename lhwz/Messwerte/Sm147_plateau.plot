set terminal png
set output 'plots/Sm147_plateau.png'

set ylabel "Aktivität Bq"
set logscale y
set xlabel "Spannung U [V]"
plot 'Sm147_plateau.txt' u 1:2:(sqrt($2)) w yerrorbars title "147-Sm"
