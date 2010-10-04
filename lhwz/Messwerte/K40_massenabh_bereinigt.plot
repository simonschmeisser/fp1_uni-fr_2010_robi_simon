set terminal png enhanced
set output 'plots/K40_massenabh_bereinigt.png'

#Messzeit fuer einzelne Messungen
t = 460
mschale = 1.2918

nuntergrund = 0.3313 # ermittelt aus extraplation

f(x) = a*(1-exp(-b*x))
a = 5.44
b = 1.7

fit f(x) 'Kalium40/massenabh_bereinigt.txt' u ($1-mschale):($2-nuntergrund):(sqrt($2/t)) via a,b

set grid
set ylabel "Aktivität [Bq]"
#set logscale y
set xlabel "Masse K-40 [g]"
plot 'Kalium40/massenabh_bereinigt.txt' u ($1-mschale):($2-nuntergrund):(sqrt($2/t)) w yerrorbars title "40-K", f(x) title "a(1-e^{bx})"
