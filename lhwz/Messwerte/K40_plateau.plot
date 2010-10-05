set terminal png enhanced size 800, 600
set output 'plots/K40_plateau.png'

#Messzeit fuer einzelne Messungen
t = 100

set grid
set ylabel "Aktivität [Bq]"
#set logscale y
set xlabel "Spannung U [V]"
plot 'Kalium40/K40_plateau.txt' u 1:2:(sqrt($2/t)) w yerrorbars title "40-K"
