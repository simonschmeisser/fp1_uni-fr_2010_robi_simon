all: plots\
     plots/U238.png plots/Sm147_plateau.png\
     plots/K40_plateau.png plots/K40_plateau2.png\
     plots/untergrund_we.png plots/untergrund_we_bereinigt.png\
     plots/K40_massenabh.png

 
plots/U238.png : U238_Pattern.txt U238_Pattern.plot
	gnuplot U238_Pattern.plot

plots/Sm147_plateau.png: Sm147_plateau.txt Sm147_plateau.plot
	gnuplot Sm147_plateau.plot

plots/K40_plateau.png: Kalium40/K40_plateau.txt K40_plateau.plot
	gnuplot K40_plateau.plot

plots/K40_plateau2.png: Kalium40/K40_plateau2.txt K40_plateau2.plot
	gnuplot K40_plateau2.plot

plots/untergrund_we.png: untergrund_we.txt untergrund_we.plot
	gnuplot untergrund_we.plot

plots/untergrund_we_bereinigt.png: untergrund_we_bereinigt.txt untergrund_we_bereinigt.plot
	gnuplot untergrund_we_bereinigt.plot

plots/K40_massenabh.png: Kalium40/massenabh.txt K40_massenabh.plot
	gnuplot K40_massenabh.plot

plots:
	mkdir plots
