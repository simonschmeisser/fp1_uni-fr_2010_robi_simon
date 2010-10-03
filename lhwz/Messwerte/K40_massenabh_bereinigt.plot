set terminal png
set output 'plots/K40_massenabh_bereinigt.png'

#Messzeit fuer einzelne Messungen
t = 460
mschale = 1.2918

set grid
set ylabel "Aktivität [Bq]"
#set logscale y
set xlabel "Masse K-40 [g]"
plot 'Kalium40/massenabh_bereinigt.txt' u ($1-mschale):2:(sqrt($2**2/t)) w yerrorbars title "40-K"
