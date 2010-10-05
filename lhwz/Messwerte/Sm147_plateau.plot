set terminal png enhanced size 800, 600
set output 'plots/Sm147_plateau.png'

#Messzeit fuer einzelne Messungen
t = 200

set grid
set ylabel "Aktivität [Bq]"
#set logscale y
set xlabel "Spannung U [V]"
plot 'Sm147_plateau.txt' u 1:2:(sqrt($2/t)) w yerrorbars title "147-Sm"
