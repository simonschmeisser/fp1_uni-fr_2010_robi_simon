set terminal png  enhanced size 800, 600
set output 'plots/untergrund_we_bereinigt.png'

#Zeit für Einzelmessung
t = 3000

#Erwarteter Verlauf
#f(x) = a*1/(1+exp(-k*G*(x-c))*(G/f-1)) 
f(x) = a*(1-exp(-b*(x-c)))+d
a = 17
b = 0.01
c = 2600
d = 0.001

f = 0.01
k = 0.00056
G = 9.7
fit [2800:3200] f(x) 'untergrund_we_bereinigt.txt' u 1:2:(sqrt($2**2/t)) via a, b, c, d

print f(3600)
print sqrt(f(3600)/t)

set ylabel "Aktivität [Bq]"
set logscale y
set grid
set xlabel "Spannung U [V]"
set xrange [0:4000]
set yrange [0.0001:]
plot 'untergrund_we.txt' u 1:2:(sqrt($2/t)) w yerrorbars title "Untergrund", 'untergrund_we_bereinigt.txt' u 1:2:(sqrt($2**2/t)) w yerrorbars title "Untergrund-bereinigt",  f(x) title "Prognostizierter Verlauf"
