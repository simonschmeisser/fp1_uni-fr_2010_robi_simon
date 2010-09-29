all: plots/U238.png plots/Sm147_plateau.png

 
plots/U238.png : U238_Pattern.txt U238_Pattern.plot
	gnuplot U238_Pattern.plot

plots/Sm147_plateau.png: Sm147_plateau.txt Sm147_plateau.plot
	gnuplot Sm147_plateau.plot

