set terminal png size 1024,786
set output 'plots/untergrund_we_bereinigt.png'

#Zeit für Einzelmessung
t = 3000


set ylabel "Aktivität [Bq]"
set logscale y
set grid
set xlabel "Spannung U [V]"
plot 'untergrund_we.txt' u 1:2:(sqrt($2**2/t)) w yerrorbars title "Untergrund", 'untergrund_we_bereinigt.txt' u 1:2:(sqrt($2**2/t)) w yerrorbars title "Untergrund-bereinigt"
